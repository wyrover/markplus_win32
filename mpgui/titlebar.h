#ifndef GUI_TITLEBAR_H
#define GUI_TITLEBAR_H

#include <QWidget>
#include <QPoint>
#include <QObject>
#include <QRect>
#include <QSize>
#include <QSettings>
#include <QMouseEvent>
#include <QDesktopWidget>
#include "mpgui.h"
#include "config.h"

namespace Ui {
class TitleBar;
}

class TitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit TitleBar(bool b_minBtn, bool b_maxBtn, bool b_cloaseBtn, QWidget *parent = 0);
    ~TitleBar();

private:
    Ui::TitleBar *ui;
    QSettings *iniSet;
    QPoint m_ptPressGlobal;
    QPoint m_ptMove;
    QRect m_rectRestoreWindow;
    bool m_bLeftBtnPress;
    bool m_bMaxWin;

private:
    void initTitleBar(bool b_minBtn, bool b_maxBtn, bool b_closeBtn);
    void initParams();
    void mouseDoubleClickEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

private slots:
    void showMaxRestore();

};

#endif // TITLEBAR_H
