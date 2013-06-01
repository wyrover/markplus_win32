#ifndef PREVIEW_H
#define PREVIEW_H

#include <QtWebKit/QWebView>

class Preview : public QWebView
{
    Q_OBJECT
public:
    explicit Preview(QWidget *parent = 0);
    
signals:
    
public slots:
    
};

#endif // PREVIEW_H
