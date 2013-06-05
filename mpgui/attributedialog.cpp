#include "attributedialog.h"
#include "ui_attributebasewidget.h"
#include <QDebug>

AttributeBaseWidget::AttributeBaseWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AttributeBaseWidget)
{
    ui->setupUi(this);
}

AttributeBaseWidget::~AttributeBaseWidget()
{
    delete ui;
}

AttributeDialog::AttributeDialog(QWidget *parent) :
    BaseDialog(parent)
{
    initAttributeDialog();
}

AttributeDialog::~AttributeDialog()
{

}

void AttributeDialog::initAttributeDialog()
{
    attBaseWidget = new AttributeBaseWidget();
    setSubWidget(attBaseWidget);
}
