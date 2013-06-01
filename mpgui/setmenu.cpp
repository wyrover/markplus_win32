#include "setmenu.h"

SetMenu::SetMenu(QWidget *parent) :
	QMenu(parent)
{
	initSetMenu();
	initActions();
}

SetMenu::~SetMenu()
{

}

void SetMenu::initSetMenu()
{
	setMinimumWidth(400);
	setMaximumWidth(400);
}

void SetMenu::initActions()
{
	editAction = new QWidgetAction(this);
	editActionBase = new EditActionBase();
	editAction->setDefaultWidget(editActionBase);
	
	zoomAction = new QWidgetAction(this);
	zoomActionBase = new ZoomActionBase();
	zoomAction->setDefaultWidget(zoomActionBase);

	viewPosts = new QAction(QObject::tr("View All Posts(H)"), this);
	viewPosts->setShortcut(QObject::tr("Ctrl+H"));
	newPost = new QAction(QObject::tr("New Post(N)"), this);
	newPost->setShortcut(QObject::tr("Ctrl+N"));
	prePost = new QAction(QObject::tr("Preview Post(R)"), this);
	prePost->setShortcut(QObject::tr("Ctrl+R"));
	pubPost = new QAction(QObject::tr("Publish Post(T)"), this);
	pubPost->setShortcut(QObject::tr("Ctrl+T"));
	find = new QAction(QObject::tr("Find(F)"), this);
	find->setShortcut(QObject::tr("Ctrl+F"));
	print = new QAction(QObject::tr("Print(P)"), this);
	print->setShortcut(QObject::tr("Ctrl+P"));
	save = new QAction(QObject::tr("Save(S)"), this);
	save->setShortcut(QObject::tr("Ctrl+S"));
	saveAs = new QAction(QObject::tr("Save As...(A)"), this);
	saveAs->setShortcut(QObject::tr("Alt+A"));
	syncPost = new QAction(QObject::tr("Sync To Clound"), this);
	setAccount = new QAction(QObject::tr("Set Your Account"), this);
	setAction = new QAction(QObject::tr("Setting"), this);
	about = new QAction(QObject::tr("About"), this);
	feedBack = new QAction(QObject::tr("Feed Back"), this);
	help = new QAction(QObject::tr("Help"), this);
	exit = new QAction(QObject::tr("Exit(X)"), this);
	exit->setShortcut(QObject::tr("Ctrl+X"));

	addAction(viewPosts);
	addAction(newPost);
	addAction(prePost);
	addAction(pubPost);
	addSeparator();
	addAction(editAction);
	addSeparator();
	addAction(zoomAction);
	addSeparator();
	addAction(find);
	addAction(print);
	addAction(save);
	addAction(saveAs);
	addSeparator();
	addAction(syncPost);
	addAction(setAccount);
	addSeparator();
	addAction(about);
	addAction(feedBack);
	addAction(help);
	addSeparator();
	addAction(exit);
}

EditActionBase::EditActionBase( QWidget* parent):
	QWidget(parent)
{
	label = new QLabel(QObject::tr("Edit"));
	cut = new QToolButton();
	cut->setText(QObject::tr("Cut"));
	copy = new QToolButton();
	copy->setText(QObject::tr("Copy"));
	paste = new QToolButton();
	paste->setText(QObject::tr("Paste"));
	layout = new QHBoxLayout();
	layout->addWidget(label);
	layout->addStretch();
	layout->addWidget(cut);
	layout->addWidget(copy);
	layout->addWidget(paste);
	layout->setSpacing(0);
	layout->setContentsMargins(35, 0, 10, 0);
	setLayout(layout);
}

ZoomActionBase::ZoomActionBase( QWidget*parent/*=0*/ ) :
	QWidget(parent)
{
	zoomLabel = new QLabel(QObject::tr("Zoom"));
	valueLabel = new QLabel(QObject::tr("100%"));
	zoomIn = new QToolButton();
	zoomIn->setText(QObject::tr("+"));
	zoomOut = new QToolButton();
	zoomOut->setText(QObject::tr("-"));
	layout = new QHBoxLayout();
	layout->addWidget(zoomLabel);
	layout->addStretch();
	layout->addWidget(zoomIn);
	layout->addWidget(valueLabel);
	layout->addWidget(zoomOut);
	layout->setSpacing(0);
	layout->setContentsMargins(35, 0, 10, 0);
	setLayout(layout);
}
