#include "windowstatus.h"
#include "QDebug"

WindowStatus::WindowStatus()
{
    initParams();
}

void WindowStatus::initParams()
{
    QSettings* iniSet = new QSettings("markplus.ini", QSettings::IniFormat, 0);
    QPoint initPosition = iniSet->value("window/position", QPoint(50, 50)).toPoint();
    QSize  initSize = iniSet->value("window/size", QSize(600, 800)).toSize();
    m_rRestoreWindow = QRect(initPosition, initSize);
    m_bMaxWin = iniSet->value("window/maxwin", false).toBool();
    m_bLeftBtnPress = false;
    m_bOnMove = false;
    m_bOnResize = false;

    qDebug() << initPosition << initSize << m_bMaxWin;

    delete iniSet;

}

void WindowStatus::setPressGlobalPoint(QPoint point)
{
    this->m_pPressGlobal = point;
}

QPoint WindowStatus::getPressGlobalPoint()
{
    return this->m_pPressGlobal;
}

void WindowStatus::setMovePoint(QPoint point)
{
    this->m_ptMove = point;
}

QPoint WindowStatus::getMovePoint()
{
    return this->m_ptMove;
}

void WindowStatus::setRestoreWindowRect(QRect rect)
{
    this->m_rRestoreWindow = rect;
}

QRect WindowStatus::getRestoreWindowRect()
{
    return this->m_rRestoreWindow;
}

void WindowStatus::setLeftButtonPress(bool press)
{
    this->m_bLeftBtnPress = press;
}

bool WindowStatus::getLeftButtonPress()
{
    return this->m_bLeftBtnPress;
}

void WindowStatus::setMaxWin(bool maxWin)
{
    this->m_bMaxWin = maxWin;
}

bool WindowStatus::getMaxWin()
{
    return this->m_bMaxWin;
}

void WindowStatus::setMaxSize(QRect rect)
{
    this->m_rMaxSize = rect;
}

QRect WindowStatus::getMaxSize()
{
    return this->m_rMaxSize;
}

void WindowStatus::setDirection(enum_Direction direction)
{
    this->m_eDirection = direction;
}

enum_Direction WindowStatus::getDirection()
{
    return this->m_eDirection;
}

void WindowStatus::setOnMove(bool onMove)
{
    this->m_bOnMove = onMove;
}

bool WindowStatus::getOnMove()
{
    return this->m_bOnMove;
}

void WindowStatus::setOnResize(bool onResize)
{
    this->m_bOnResize = onResize;
}

bool WindowStatus::getOnResize()
{
    return this->m_bOnResize;
}
