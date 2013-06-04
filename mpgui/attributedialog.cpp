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
    initDefaultSkin();
}

void AttributeDialog::initDefaultSkin()
{
    QString qss;
    QFile qssFile("://res/skin/default.qss");
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
        qss = QLatin1String(qssFile.readAll());
        qDebug() << qss;
        setStyleSheet(qss);
        qssFile.close();
    }
}
