#ifndef CONFIG_H
#define CONFIG_H

#define INIFILE "markplus.ini"

#define VALUE_DIS 3
#define VALUE_TITLE_HEIGHT 40

enum enum_Direction
   {
       eNone,
       eTop = 1,
       eRight =2 ,
       eBottom =4,
       eLeft = 8,
       eTopRight = eTop + eRight,
       eRightBottom = eRight + eBottom,
       eBottomLeft = eBottom + eLeft,
       eLeftTop = eLeft + eTop
   };

#endif // CONFIG_H
