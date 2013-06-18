#include "ui_mpgui.h"
#include "mpgui.h"
#include "QDebug"

MpGui::MpGui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MpGui)
{
    ui->setupUi(this);
    setWindowFlags( Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    initWorkWidget();
    initStatusBar();
    initStyleSheet();
    initMpGui();
}

MpGui::~MpGui()
{
    delete ui;
}

void MpGui::initMpGui()
{
    windowStatus = new WindowStatus();
    setGeometry(windowStatus->getRestoreWindowRect());
    statusBar->setSizeGripEnabled(!windowStatus->getMaxWin());
    windowStatus->setMaxSize(qApp->desktop()->availableGeometry());
}

void MpGui::initStatusBar()
{
    //初始化状态栏
    statusBar = new StatusBar();
    ui->statusBarLayout->addWidget(statusBar);
}

StatusBar* MpGui::getStatusBar()
{
    return this->statusBar;
}

void MpGui::initWorkWidget()
{
    //初始化workwidget
    workWidget = new WorkWidget();
    ui->centralEditLayout->addWidget(workWidget);
}

void MpGui::initStyleSheet()
{
    QString qss;
    QFile qssFile("://res/skin/default.qss");
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
        qss = QLatin1String(qssFile.readAll());
        qApp->setStyleSheet(qss);
        qssFile.close();
    }
}

void MpGui::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton && event->y() <= 40)
        showMaxRestore();
    windowStatus->setLeftButtonPress(false);
    windowStatus->setOnMove(false);
}

void MpGui::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "x = " << event->x() << ";y = " << event->y() << ";left" << windowStatus->getLeftButtonPress();
    if(!windowStatus->getLeftButtonPress())
    {
        windowStatus->setDirection(pointValid(event->x(), event->y()));
        setCursorSytle(windowStatus->getDirection());
    }
    else if(!windowStatus->getMaxWin() && !windowStatus->getOnResize() && (windowStatus->getOnMove() || event->y() <= VALUE_TITLE_HEIGHT && event->y() > VALUE_DIS && event->x() > VALUE_DIS && width() - event->x() > VALUE_DIS))
    {
        QPoint pMove = event->globalPos();
        windowStatus->setMovePoint(pMove);
        move(pos() + pMove - windowStatus->getPressGlobalPoint());
        windowStatus->setPressGlobalPoint(pMove);
        windowStatus->setOnMove(true);
    }
    else if(!windowStatus->getOnMove())
    {
        // 调整大小
        int nXGlobal = event->globalX();
        int nYGlobal = event->globalY();
        setDrayMove(nXGlobal, nYGlobal, windowStatus->getDirection());
        windowStatus->setPressGlobalPoint(QPoint(nXGlobal, nYGlobal));
        windowStatus->setOnResize(true);
    }
}

void MpGui::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        windowStatus->setLeftButtonPress(true);
        windowStatus->setPressGlobalPoint(event->globalPos());
    }
    event->ignore();
}

void MpGui::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        windowStatus->setLeftButtonPress(false);
        windowStatus->setOnResize(false);
        windowStatus->setOnMove(false);
    }
    event->ignore();
}

void MpGui::showMaxRestore()
{
    if(!windowStatus->getMaxWin())
    {
        windowStatus->setRestoreWindowRect(geometry());
        setGeometry(qApp->desktop()->availableGeometry());
        statusBar->setSizeGripEnabled(windowStatus->getMaxWin());
    }
    else
    {
        setGeometry(windowStatus->getRestoreWindowRect());
        statusBar->setSizeGripEnabled(true);
    }
    windowStatus->setLeftButtonPress(false);
    windowStatus->setMaxWin(!windowStatus->getMaxWin());
}

enum_Direction MpGui::pointValid(int nXRelative, int nYRelative)
{
    int nTop = qAbs(nYRelative) < VALUE_DIS ? eTop:eNone;
    int nRight = qAbs(nXRelative-rect().right())< VALUE_DIS ? eRight:eNone;
    int nBottom = qAbs(nYRelative-rect().bottom())< VALUE_DIS ? eBottom:eNone;
    int nLeft = qAbs(nXRelative) < VALUE_DIS ? eLeft:eNone;

    return enum_Direction(nTop + nRight + nBottom + nLeft);
}

void MpGui::setCursorSytle(enum_Direction direction)
{
    //设置上下左右以及右上、右下、左上、坐下的鼠标形状
    switch(direction)
    {
        case eTop:
        case eBottom:
            setCursor(Qt::SizeVerCursor);
            break;
        case eRight:
            setCursor(Qt::SizeHorCursor);
            break;
        case eLeft:
            setCursor(Qt::SizeHorCursor);
            break;
        case eTopRight:
        case eBottomLeft:
            setCursor(Qt::SizeBDiagCursor);
            break;
        case eRightBottom:
        case eLeftTop:
            setCursor(Qt::SizeFDiagCursor);
            break;
        default:
            setCursor(Qt::ArrowCursor);
            break;
    }
}

void MpGui::setDrayMove(int nXGlobal, int nYGlobal, enum_Direction direction)
{
    //计算偏差
    int ndX = nXGlobal - windowStatus->getPressGlobalPoint().x();
    int ndY = nYGlobal - windowStatus->getPressGlobalPoint().y();
    //获得主窗口位置信息
    QRect rectWindow = geometry();
    //判别方向
    if(direction & eTop)
    {
        rectWindow.setTop(rectWindow.top()+ndY);
    }
    if(direction & eRight)
    {
        rectWindow.setRight(rectWindow.right()+ndX);
    }
    if(direction & eBottom)
    {
        rectWindow.setBottom(rectWindow.bottom()+ndY);
    }
    if(direction & eLeft)
    {
        rectWindow.setLeft(rectWindow.left()+ndX);
    }
    if(rectWindow.width()< minimumWidth() || rectWindow.height()<minimumHeight())
    {
        return;
    }
    //重新设置窗口位置为新位置信息
    if(rectWindow.width() < windowStatus->getMaxSize().width()
            && rectWindow.height() < windowStatus->getMaxSize().height())
        setGeometry(rectWindow);
}
