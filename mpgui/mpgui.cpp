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
