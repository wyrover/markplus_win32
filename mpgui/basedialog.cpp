#include "basedialog.h"
#include "ui_basedialog.h"
#include "QDebug"

BaseDialog::BaseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BaseDialog)
{
    ui->setupUi(this);
    initBaseDialog();
}

BaseDialog::~BaseDialog()
{
    delete ui;
}

void BaseDialog::initBaseDialog()
{
    setWindowFlags( Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    leftBtnDown = false;
}

void BaseDialog::mouseMoveEvent(QMouseEvent *event)
{
    if(leftBtnDown)
    {
        ptMove = event->globalPos();
        move(pos() + ptMove - ptPressGlobal);
        ptPressGlobal = ptMove;
    }
    event->ignore();
}

void BaseDialog::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        ptPressGlobal = event->globalPos();
        leftBtnDown = true;
    }
    event->ignore();
}

void BaseDialog::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        leftBtnDown = false;
    }
    event->ignore();
}

void BaseDialog::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        leftBtnDown = false;
    }
    event->ignore();
}

void BaseDialog::setSubWidget(QWidget *widget)
{
    ui->subLayout->addWidget(widget);
}
