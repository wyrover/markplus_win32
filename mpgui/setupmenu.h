#ifndef SETUPMENU_H
#define SETUPMENU_H

#include <QMenu>

class SetupMenu : public QMenu
{
    Q_OBJECT
public:
    explicit SetupMenu(QWidget *parent = 0);

    QAction* editPost;
    QAction* prePost;
    QAction* doubleView;
    QAction* pubPost;
    QAction* find;
    QAction* print;
    QAction* save;
    QAction* saveToHtml;
    QAction* syncPost;
    QAction* setAccount;
    QAction* setAction;
    QAction* about;
    QAction* feedBack;
    QAction* help;
    QAction* exit;
    QAction* asciCodeAction;
    QMenu *codeMenu;


private:
    void initSetMenu();
    void initActions();
    void showEvent(QShowEvent *);
    
signals:
    void setupMenuShowSignal();
};

#endif // SETUPMENU_H
