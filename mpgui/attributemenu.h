#ifndef ATTRIBUTEMENU_H
#define ATTRIBUTEMENU_H

#include <QWidget>
#include <QMenu>
#include <QWidgetAction>

namespace Ui {
class AttributeBaseWidget;
}

class AttributeBaseWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AttributeBaseWidget(QWidget *parent = 0);
    ~AttributeBaseWidget();

private:
    Ui::AttributeBaseWidget *ui;
};

class AttributeMenu : public QMenu
{
    Q_OBJECT

public:
    explicit AttributeMenu(QWidget *parent = 0);
    ~AttributeMenu();

private:
    AttributeBaseWidget* attBaseWidget;
    QWidgetAction* attAction;

    void initAttributeMenu();
};

#endif // ATTRIBUTEMENU_H
