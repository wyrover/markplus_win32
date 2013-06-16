#ifndef MDEDITOR_H
#define MDEDITOR_H

#include <QPainter>
#include <QSettings>
#include <QTextBlock>
#include <QTextEdit>
#include <QPlainTextEdit>

class QWidget;
class QHBoxLayout;
class MdEditor;
class TextEditBase;
class TextEditMetaBorder;

class TextEditBase : public QPlainTextEdit
{
	Q_OBJECT
public:
	explicit TextEditBase(QWidget *parent = 0);
	virtual ~TextEditBase();

	void metaBorderPaintEvent(QPaintEvent *e);
	int metaBorderWidth() const;

protected:
	void resizeEvent(QResizeEvent *event);

private slots:
	void updateMetaBorderWidth(int newBlockCount);
	void updateMetaBorder(const QRect &, int);
	void highlightCurrentLine();

private:
	TextEditMetaBorder *    _metaBorder;
};

class MdEditor : public TextEditBase
{
	Q_OBJECT

public:
	MdEditor(QWidget *parent = 0);
	~MdEditor();

protected:
	virtual void hideEvent(QHideEvent *ev);

private:
	void readSettings();
	void writeSettings();
};

class TextEditMetaBorder : public QWidget
{
	Q_OBJECT
public:
	explicit TextEditMetaBorder(TextEditBase *editor);
	virtual ~TextEditMetaBorder();

	QSize sizeHint() const;

protected:
	virtual void paintEvent(QPaintEvent *e);

private:
	TextEditBase *  _editor;

};

#endif // MDEDITOR_H
