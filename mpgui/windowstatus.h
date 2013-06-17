#ifndef WINDOWSTATUS_H
#define WINDOWSTATUS_H

#include <QPoint>
#include <QRect>
#include <QSettings>
#include <QMouseEvent>
#include <QDesktopWidget>
#include "config.h"

#define VALUE_DIS 5
#define VALUE_TITLE_HEIGHT 20

class WindowStatus
{
public:
    WindowStatus();
    QPoint getPressGlobalPoint();
    QPoint getMovePoint();
    QRect getRestoreWindowRect();
    bool getLeftButtonPress();
    bool getMaxWin();
    void setPressGlobalPoint(QPoint point);
    void setMovePoint(QPoint point);
    void setRestoreWindowRect(QRect rect);
    void setLeftButtonPress(bool press);
    void setMaxWin(bool maxWin);

private:
    void initParams();
    QPoint m_pPressGlobal;
    QPoint m_ptMove;
    QRect m_rectRestoreWindow;
    bool m_bLeftBtnPress;
    bool m_bMaxWin;

};

#endif // WINDOWSTATUS_H
