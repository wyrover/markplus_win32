#include "setupmenu.h"
#include "QDebug"

SetupMenu::SetupMenu(QWidget *parent) :
    QMenu(parent)
{
    initSetMenu();
    initActions();
}

void SetupMenu::initSetMenu()
{
    setMinimumWidth(400);
    setMaximumWidth(400);
}

void SetupMenu::initActions()
{
    editPost = new QAction(QObject::tr("Editor View"), this);
    editPost->setShortcut(QObject::tr("Ctrl+E"));
    prePost = new QAction(QObject::tr("Preview View(P)"), this);
    prePost->setShortcut(QObject::tr("Ctrl+P"));
    doubleView = new QAction(QObject::tr("Double View(D)"), this);
    doubleView->setShortcut(QObject::tr("Ctrl+D"));
    pubPost = new QAction(QObject::tr("Publish Post(T)"), this);
    pubPost->setShortcut(QObject::tr("Ctrl+T"));
    find = new QAction(QObject::tr("Find(F)"), this);
    find->setShortcut(QObject::tr("Ctrl+F"));
    print = new QAction(QObject::tr("Print(P)"), this);
    print->setShortcut(QObject::tr("Ctrl+Alt+P"));
    save = new QAction(QObject::tr("Save(S)"), this);
    save->setShortcut(QObject::tr("Ctrl+S"));
    saveToHtml = new QAction(QObject::tr("Save To Html(H)"), this);
    saveToHtml->setShortcut(QObject::tr("Ctrl+H"));
    syncPost = new QAction(QObject::tr("Sync To Clound"), this);
    setAccount = new QAction(QObject::tr("Set Your Account"), this);
    setAction = new QAction(QObject::tr("Setting"), this);
    about = new QAction(QObject::tr("About"), this);
    feedBack = new QAction(QObject::tr("Feed Back"), this);
    help = new QAction(QObject::tr("Help"), this);
    exit = new QAction(QObject::tr("Exit(X)"), this);
    exit->setShortcut(QObject::tr("Ctrl+X"));

    addAction(doubleView);
    addAction(editPost);
    addAction(prePost);
    //addAction(pubPost);
    addSeparator();
    //addAction(find);
    //addAction(print);
    addAction(save);
    addAction(saveToHtml);
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

void SetupMenu::showEvent(QShowEvent *)
{
    emit setupMenuShowSignal();
}
