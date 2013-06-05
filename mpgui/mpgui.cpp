#include "ui_mpgui.h"
#include "mpgui.h"

MpGui::MpGui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MpGui)
{
    ui->setupUi(this);
    setWindowFlags( Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    initTitleBar();
    initWorkWidget();
    initStatusBar();
    initStyleSheet();
}

MpGui::~MpGui()
{
    delete ui;
}

void MpGui::initTitleBar()
{
    //初始化标题栏
    titleBar = new TitleBar(true, true, true, this);
    ui->mainLayout->addWidget(titleBar);
}

void MpGui::initStatusBar()
{
    //初始化状态栏
    statusBar = new StatusBar();
    ui->mainLayout->addWidget(statusBar);
}

StatusBar* MpGui::getStatusBar()
{
    return this->statusBar;
}

void MpGui::initWorkWidget()
{
    //初始化workwidget
    workWidget = new WorkWidget();
    ui->mainLayout->addWidget(workWidget);
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
