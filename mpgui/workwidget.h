#ifndef WORKWIDGET_H
#define WORKWIDGET_H

#include <QPoint>
#include <QWidget>
#include <QAction>
#include <QList>
#include <QSplitter>
#include <QToolButton>
#include <QtWebKit/QWebView>
#include "setmenu.h"
#include "mdeditor.h"
#include "preview.h"
#include "attributedialog.h"

namespace Ui {
    class WorkWidget;
}

class WorkWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WorkWidget(QWidget *parent = 0);
    ~WorkWidget();

private:
    Ui::WorkWidget *ui;
    SetMenu *setMenu;
    MdEditor *mdEditor;
    Preview *preview;
    AttributeDialog *attributeDialog;

private:
    void initWorkWidget();
    void initToolBar();
    void initEditor();
    void initPreview();
    void switchViewModel(bool, bool, bool);

private slots:
    void on_signalBtn_clicked();
    void on_previewBtn_clicked();
    void on_doubleBtn_clicked();
    void on_setBtn_toggled(bool checked);
    void on_attributeBtn_clicked();
};

#endif // WORKWIDGET_H
