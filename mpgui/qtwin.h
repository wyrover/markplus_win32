#ifndef GUI_QTWIN_H
#define GUI_QTWIN_H

#include <QColor>
#include <QWidget>

class WindowNotifier;

class QtWin
{
public:
    static bool enableAeroWindow(QWidget *widget, bool enable = true);
    static bool extendFrameIntoClientArea(QWidget *widget,
                                          int left = -1, int top = -1,
                                          int right = -1, int bottom = -1);
    static bool isCompositionEnabled();
    static QColor colorizatinColor();

private:
    static WindowNotifier *windowNotifier();
};

#endif // GUI_QTWIN_H
