#ifndef MPGUI_H
#define MPGUI_H

#include <QWidget>
#include <QFrame>
#include "mpgui_global.h"
#include "titlebar.h"
#include "statusbar.h"
#include "workwidget.h"
#include "windowstatus.h"

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
    StatusBar *statusBar;
    WorkWidget *workWidget;
    WindowStatus *windowStatus;

    void initMpGui();
    void initStatusBar();
    void initWorkWidget();
    void initStyleSheet();
    void showMaxRestore();

    void mouseDoubleClickEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

};

#endif // MPGUI_H
