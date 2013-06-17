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
    m_rectRestoreWindow = QRect(initPosition, initSize);
    m_bMaxWin = iniSet->value("window/maxwin", false).toBool();
    m_bLeftBtnPress = false;

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
    this->m_rectRestoreWindow = rect;
}

QRect WindowStatus::getRestoreWindowRect()
{
    return this->m_rectRestoreWindow;
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
