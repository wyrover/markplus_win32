#ifndef ATTRIBUTEDIALOG_H
#define ATTRIBUTEDIALOG_H

#include <QWidget>
#include "basedialog.h"

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

class AttributeDialog : public BaseDialog
{
    Q_OBJECT

public:
    explicit AttributeDialog(QWidget *parent = 0);
    ~AttributeDialog();

private:
    AttributeBaseWidget* attBaseWidget;
    void initAttributeDialog();
    void initDefaultSkin();
};

#endif // ATTRIBUTEDIALOG_H
