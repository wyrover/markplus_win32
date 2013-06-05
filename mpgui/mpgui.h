#ifndef MPGUI_H
#define MPGUI_H

#include <QWidget>
#include <QFrame>
#include "mpgui_global.h"
#include "titlebar.h"
#include "statusbar.h"
#include "workwidget.h"

namespace Ui {
    class MpGui;
}

class TitleBar;

class MPGUISHARED_EXPORT MpGui : public QWidget
{
    Q_OBJECT

public:
    explicit MpGui(QWidget *parent = 0);
    ~MpGui();
    StatusBar* getStatusBar();

private:
    Ui::MpGui *ui;
    TitleBar *titleBar;
    StatusBar *statusBar;
    WorkWidget *workWidget;

    void initTitleBar();
    void initStatusBar();
    void initWorkWidget();
    void initStyleSheet();

};

#endif // MPGUI_H
