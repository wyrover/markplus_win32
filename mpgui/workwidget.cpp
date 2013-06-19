#include "workwidget.h"
#include "ui_workwidget.h"
#include <QDebug>

WorkWidget::WorkWidget(QWidget *parent) :
QWidget(parent),
    ui(new Ui::WorkWidget)
{
    ui->setupUi(this);
    initToolBar();
    initEditor();
    initPreview();
    initWorkWidget();
}

WorkWidget::~WorkWidget()
{
    delete ui;
}

void WorkWidget::initWorkWidget()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->doubleBtn->setChecked(true);
    QList<int> splitterSizes;
    splitterSizes.append(ui->editorPage->width()/2);
    splitterSizes.append(ui->editorPage->width()/2);
    ui->splitter->setSizes(splitterSizes);
}

void WorkWidget::initEditor()
{
    mdEditor = new MdEditor();
    mdEditor->setReadOnly(false);
    ui->splitter->addWidget(mdEditor);

    connect(mdEditor, SIGNAL(textChanged()), this, SLOT(editorToPreview()));
}

void WorkWidget::initPreview()
{
    preview = new Preview();
    preview->setHtml("<h1>Welcome to the world of Markdown</h1><hr/><ul><li>aaa</li><li>bbb</li><li>ccc</li></ul>");
    qDebug() << ui->editorPage->width();
    ui->splitter->addWidget(preview);
}

void WorkWidget::initToolBar()
{
    setupMenu = new SetupMenu();
    setupMenu->setObjectName("setupMenu");
    ui->setBtn->setMenu(setupMenu);

    connect(setupMenu, SIGNAL(setupMenuShowSignal()), this, SLOT(adjustSetupMenu()));
    connect(setupMenu->prePost, SIGNAL(triggered()), this, SLOT(on_previewBtn_clicked()));
    connect(setupMenu->editPost, SIGNAL(triggered()), this, SLOT(on_signalBtn_clicked()));
    connect(setupMenu->doubleView, SIGNAL(triggered()), this, SLOT(on_doubleBtn_clicked()));
}

void WorkWidget::switchViewModel( bool singalFlag, bool previewFlag, bool doubleFlag)
{

    if(singalFlag)
    {
        mdEditor->show();
        preview->hide();
    }
    if(previewFlag)
    {
        mdEditor->hide();
        preview->show();
    }
    if (doubleFlag)
    {
        preview->show();
        mdEditor->show();
    }
    ui->signalBtn->setChecked(singalFlag);
    ui->previewBtn->setChecked(previewFlag);
    ui->doubleBtn->setChecked(doubleFlag);
}

void WorkWidget::on_signalBtn_clicked()
{
    switchViewModel(true, false, false);
}

void WorkWidget::on_previewBtn_clicked()
{
    switchViewModel(false, true, false);
}

void WorkWidget::on_doubleBtn_clicked()
{
    switchViewModel(false, false, true);
}

void WorkWidget::on_attributeBtn_clicked()
{
    attributeDialog = new AttributeDialog();
    attributeDialog->show();
}

void WorkWidget::editorToPreview()
{
    QString html;
    QStringList markdown = mdEditor->toPlainText().split("\n");
    MpLog log;
    for(int i = 0;i < markdown.size();i++)
        html.append(mparse.markdownToHtml(filertIllegChar(markdown.at(i))));
    qDebug() << html;
    preview->setHtml(html);
}

QString WorkWidget::filertIllegChar(QString str)
{
    str.replace("\\", "\\\\");
    str.replace("\"", "\\\"");
    str.replace("\'", "\\\'");
    str.append("\\n");
    return str;
}

void WorkWidget::adjustSetupMenu()
{
    QPoint pos = mapToGlobal(ui->setBtn->pos());
    pos.setX(pos.x() + ui->setBtn->width() - setupMenu->width());
    pos.setY(pos.y() + ui->setBtn->height());
    setupMenu->popup(pos);
    qDebug() << pos;
}
