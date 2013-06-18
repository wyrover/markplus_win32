#ifndef WINDOWSTATUS_H
#define WINDOWSTATUS_H

#include <QPoint>
#include <QRect>
#include <QSettings>
#include <QMouseEvent>
#include <QDesktopWidget>
#include "config.h"

class WindowStatus
{
public:
    WindowStatus();
    QPoint getPressGlobalPoint();
    QPoint getMovePoint();
    QRect getRestoreWindowRect();
    QRect getMaxSize();
    bool getLeftButtonPress();
    bool getMaxWin();
    bool getOnMove();
    bool getOnResize();
    enum_Direction getDirection();
    void setPressGlobalPoint(QPoint point);
    void setMovePoint(QPoint point);
    void setRestoreWindowRect(QRect rect);
    void setLeftButtonPress(bool press);
    void setMaxWin(bool maxWin);
    void setMaxSize(QRect rect);
    void setDirection(enum_Direction direction);
    void setOnMove(bool onMove);
    void setOnResize(bool onResize);

private:
    void initParams();
    QPoint m_pPressGlobal;
    QPoint m_ptMove;
    QRect m_rRestoreWindow;
    QRect m_rMaxSize;
    bool m_bLeftBtnPress;
    bool m_bMaxWin;
    bool m_bOnMove;
    bool m_bOnResize;
    enum_Direction m_eDirection;

};

#endif // WINDOWSTATUS_H
