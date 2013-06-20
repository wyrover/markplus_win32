#ifndef WORKWIDGET_H
#define WORKWIDGET_H

#include <QPoint>
#include <QWidget>
#include <QAction>
#include <QList>
#include <QSplitter>
#include <QToolButton>
#include <QStringList>
#include <QFileDialog>
#include <QMessageBox>
#include <QtWebKit/QWebView>
#include "mdeditor.h"
#include "preview.h"
#include "attributedialog.h"
#include "mparse.h"
#include "mplog.h"
#include "setupmenu.h"

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
    MdEditor *mdEditor;
    Preview *preview;
    AttributeDialog *attributeDialog;
    Mparse mparse;
    SetupMenu *setupMenu;
    QString html;
    QString markdown;

private:
    void initWorkWidget();
    void initToolBar();
    void initEditor();
    void initPreview();
    void switchViewModel(bool, bool, bool);
    QString filertIllegChar(QString str);
    bool newPostFlag;

private slots:
    void on_signalBtn_clicked();
    void on_previewBtn_clicked();
    void on_doubleBtn_clicked();
    void on_attributeBtn_clicked();
    void editorToPreview();
    void adjustSetupMenu();
    void saveMarkdownFile();
    void saveHtmlFile();
    void on_newBtn_clicked();
};

#endif // WORKWIDGET_H
