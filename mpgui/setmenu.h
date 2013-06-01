#ifndef SETMENU_H
#define SETMENU_H

#include <QObject>
#include <QMenu>
#include <QAction>
#include <QLabel>
#include <QToolButton>
#include <QWidgetAction>
#include <QHBoxLayout>

class EditActionBase : public QWidget
{
	Q_OBJECT

public:
	explicit EditActionBase(QWidget*parent=0);
private:
	QLabel* label;
	QHBoxLayout* layout;
	QToolButton* cut;
	QToolButton* copy;
	QToolButton* paste;
};
class ZoomActionBase : public QWidget
{
	Q_OBJECT

public:
	explicit ZoomActionBase(QWidget*parent=0);
private:
	QLabel* zoomLabel;
	QLabel* valueLabel;
	QToolButton* zoomIn;
	QToolButton* zoomOut;
	QHBoxLayout* layout;
};

class SetMenu : public QMenu
{
	Q_OBJECT

public:
	explicit SetMenu(QWidget *parent = 0);
	~SetMenu();

private:
	EditActionBase* editActionBase;
	ZoomActionBase* zoomActionBase;

	QWidgetAction* editAction;
	QWidgetAction* zoomAction;
	QAction* viewPosts;
	QAction* newPost;
	QAction* prePost;
	QAction* pubPost;
	QAction* find;
	QAction* print;
	QAction* save;
	QAction* saveAs;
	QAction* syncPost;
	QAction* setAccount;
	QAction* setAction;
	QAction* about;
	QAction* feedBack;
	QAction* help;
	QAction* exit;

private:
	void initSetMenu();
	void initActions();
};

#endif // SETMENU_H
