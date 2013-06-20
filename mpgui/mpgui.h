#ifndef MPGUI_H
#define MPGUI_H

#include <QWidget>
#include <QFrame>
#include "mpgui_global.h"
#include "statusbar.h"
#include "workwidget.h"
#include "windowstatus.h"
#include "config.h"

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

private slots:
    void on_closeBtn_clicked();

    void on_maxBtn_clicked();

    void on_minBtn_clicked();

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
    void setCursorSytle(enum_Direction direction);
    void setDrayMove(int nXRelative, int nYRelative, enum_Direction direction);
    enum_Direction pointValid(int nXRelative, int nYRelative);

    void mouseDoubleClickEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

};

#endif // MPGUI_H
