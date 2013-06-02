#include "attributemenu.h"
#include "ui_attributebasewidget.h"

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

AttributeMenu::AttributeMenu(QWidget *parent) :
    QMenu(parent)
{
    initAttributeMenu();
}

AttributeMenu::~AttributeMenu()
{

}

void AttributeMenu::initAttributeMenu()
{
    attAction = new QWidgetAction(this);
    attBaseWidget = new AttributeBaseWidget();
    attAction->setDefaultWidget(attBaseWidget);
    addAction(attAction);
}
