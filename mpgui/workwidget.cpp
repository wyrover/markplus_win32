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
    mdEditor->setObjectName("mdEditor");
    mdEditor->setReadOnly(false);
    ui->splitter->addWidget(mdEditor);
    markdown = "###Welcome to the world of markdown\n* you can edit the text with markdown\n* you can preview the document\n* you can export the text to local file";
    mdEditor->insertPlainText(markdown);

    connect(mdEditor, SIGNAL(textChanged()), this, SLOT(editorToPreview()));
}

void WorkWidget::initPreview()
{
    preview = new Preview();
    editorToPreview();
    preview->setHtml(html);
    qDebug() << ui->editorPage->width();
    ui->splitter->addWidget(preview);
}

void WorkWidget::initToolBar()
{
    setupMenu = new SetupMenu();
    setupMenu->setObjectName("setupMenu");
    ui->setBtn->setMenu(setupMenu);
    newPostFlag = false;

    connect(setupMenu, SIGNAL(setupMenuShowSignal()), this, SLOT(adjustSetupMenu()));
    connect(setupMenu->prePost, SIGNAL(triggered()), this, SLOT(on_previewBtn_clicked()));
    connect(setupMenu->editPost, SIGNAL(triggered()), this, SLOT(on_editorBtn_clicked()));
    connect(setupMenu->doubleView, SIGNAL(triggered()), this, SLOT(on_doubleBtn_clicked()));
    connect(setupMenu->open, SIGNAL(triggered()), this, SLOT(openMarkdownFile()));
    connect(setupMenu->save, SIGNAL(triggered()), this, SLOT(saveMarkdownFile()));
    connect(setupMenu->saveToHtml, SIGNAL(triggered()), this, SLOT(saveHtmlFile()));
    connect(setupMenu->exit, SIGNAL(triggered()), qApp, SLOT(quit()));
}

void WorkWidget::switchViewModel( bool editorFlag, bool previewFlag, bool doubleFlag)
{

    if(editorFlag)
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
    ui->editorBtn->setChecked(editorFlag);
    ui->previewBtn->setChecked(previewFlag);
    ui->doubleBtn->setChecked(doubleFlag);
}

void WorkWidget::on_editorBtn_clicked()
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

void WorkWidget::on_newBtn_clicked()
{
    if(!mdEditor->toPlainText().isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("Do you want to save the text");
        msgBox.setIcon(QMessageBox::Question);
        msgBox.setStandardButtons(QMessageBox::Yes  | QMessageBox::No | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Cancel);
        int ret = msgBox.exec();
        qDebug() << ret;
        if(ret == 16384)
        {
            newPostFlag = true;
            saveMarkdownFile();
        }
        else if(ret == 65536)
        {
            mdEditor->clear();
        }
    }
}

void WorkWidget::editorToPreview()
{
    markdown = mdEditor->toPlainText();
    html = mparse.markdownToHtml(filertIllegChar(markdown));
    QString style = "<html><body style='font-family:Segoe UI'>" + html + "</body></html>";
    qDebug() << style;
    preview->setHtml(style);
}

QString WorkWidget::filertIllegChar(QString str)
{
    str.replace("\\", "\\\\");
    str.replace("\"", "\\\"");
    str.replace("\'", "\\\'");
    str.replace("\n", "\\n");
    return str;
}

void WorkWidget::adjustSetupMenu()
{
    QPoint pos = mapToGlobal(ui->setBtn->pos());
    pos.setX(pos.x() + ui->setBtn->width() - setupMenu->width());
    pos.setY(pos.y() + ui->setBtn->height());
    setupMenu->popup(pos);
}

void WorkWidget::saveMarkdownFile()
{
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save as markdown file"), ".", "Markdown file(*.md *.markdown)");
    if(!filePath.isEmpty()) {
        QFile file(filePath);
        //方式：Append为追加，WriteOnly，ReadOnly
        if (!file.open(QIODevice::WriteOnly|QIODevice::Text)) {
            QMessageBox::critical(NULL, tr("note"), tr("can not create file"));
            return;
        }
        QTextStream out(&file);;
        out << markdown;
        out.flush();
        file.close();
    }
    if(newPostFlag)
    {
        mdEditor->clear();
        newPostFlag = false;
    }
}

void WorkWidget::saveHtmlFile()
{
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save as html file"), ".", "Html file(*.html *.htm)");
    if(!filePath.isEmpty()) {
        QFile file(filePath);
        //方式：Append为追加，WriteOnly，ReadOnly
        if (!file.open(QIODevice::WriteOnly|QIODevice::Text)) {
            QMessageBox::critical(NULL, tr("note"), tr("can not create file"));
            return;
        }
        QTextStream out(&file);
        out << html;
        out.flush();
        file.close();
    }
}

void WorkWidget::openMarkdownFile()
{
    if(mdEditor->toPlainText().isEmpty()){
        QString filePath = QFileDialog::getOpenFileName(this, tr("Open"), ".", "Markdown file(*.md *.markdown)");
        if(!filePath.isEmpty()){
            QFile mdFile(filePath);
            mdFile.open(QFile::ReadOnly);
            if(mdFile.isOpen())
            {
                markdown = QLatin1String(mdFile.readAll());
                mdEditor->setPlainText(markdown);
                mdFile.close();
            }
        }
    }else{
        QMessageBox msgBox;
        msgBox.setText("Do you want to save the text");
        msgBox.setIcon(QMessageBox::Question);
        msgBox.setStandardButtons(QMessageBox::Yes  | QMessageBox::No | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Cancel);
        int ret = msgBox.exec();
        qDebug() << ret;
        if(ret == 16384)
        {
            newPostFlag = true;
            saveMarkdownFile();
            openMarkdownFile();
        }
        else if(ret == 65536)
        {
            mdEditor->clear();
            openMarkdownFile();
        }
    }
}
