#include "titlebar.h"
#include "ui_titlebar.h"

TitleBar::TitleBar(bool b_minBtn, bool b_maxBtn, bool b_closeBtn, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TitleBar)
{
    ui->setupUi(this);
    initTitleBar(b_minBtn, b_maxBtn, b_closeBtn);
    initParams();
}

TitleBar::~TitleBar()
{
    delete ui;
}

void TitleBar::initTitleBar(bool b_minBtn, bool b_maxBtn, bool b_closeBtn)
{
    if(!b_minBtn)
    {
        ui->minBtn->hide();
    }
    if(!b_maxBtn)
    {
        ui->maxBtn->hide();
    }
    if(!b_closeBtn)
    {
        ui->closeBtn->hide();
    }

    MpGui *pMpGui = (qobject_cast<MpGui *> (parent()));
    connect(ui->closeBtn, SIGNAL(clicked()), pMpGui, SLOT(close()));
    connect(ui->minBtn, SIGNAL(clicked()), pMpGui, SLOT(showMinimized()));
    connect(ui->maxBtn, SIGNAL(clicked()), this, SLOT(showMaxRestore()));
}

void TitleBar::initParams()
{
    iniSet = new QSettings("markplus.ini", QSettings::IniFormat, 0);
    m_bMaxWin = true;
    m_bLeftBtnPress = false;
    MpGui *pMpGui = (qobject_cast<MpGui *> (parent()));
    pMpGui->setGeometry(qApp->desktop()->availableGeometry());	//设置窗口最大化
    pMpGui->getStatusBar()->setSizeGripEnabled(false);  //禁用调整大小
}

void TitleBar::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bLeftBtnPress = false;
        showMaxRestore();
        m_bMaxWin = !m_bMaxWin;
    }
    event->ignore();
}

void TitleBar::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bLeftBtnPress && !m_bMaxWin)
    {
        m_ptMove = event->globalPos();
        MpGui *pMpGui = (qobject_cast<MpGui *> (parent()));
        pMpGui->move(pMpGui->pos() + m_ptMove - m_ptPressGlobal);
        m_ptPressGlobal = m_ptMove;
    }
    event->ignore();
}

void TitleBar::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_ptPressGlobal = event->globalPos();
        m_bLeftBtnPress = true;
    }
    event->ignore();
}

void TitleBar::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bLeftBtnPress = false;
    }
    event->ignore();
}

void TitleBar::showMaxRestore()
{
    MpGui* pMpGui = (qobject_cast<MpGui *> (parent()));
    if(!m_bMaxWin)
    {
        m_rectRestoreWindow = pMpGui->geometry();
        pMpGui->setGeometry(qApp->desktop()->availableGeometry());
        pMpGui->getStatusBar()->setSizeGripEnabled(false);  //禁用调整大小
    }
    else
    {
        pMpGui->setGeometry(m_rectRestoreWindow);
        pMpGui->getStatusBar()->setSizeGripEnabled(true);  //开启调整大小
    }
}
