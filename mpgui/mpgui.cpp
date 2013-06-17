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

}

void MpGui::mouseMoveEvent(QMouseEvent *event)
{

}

void MpGui::mousePressEvent(QMouseEvent *event)
{

}

void MpGui::mouseReleaseEvent(QMouseEvent *event)
{

}
