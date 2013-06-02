#ifndef BASEDIALOG_H
#define BASEDIALOG_H

#include <QDialog>
#include <QPoint>
#include <QMouseEvent>
#include <QVBoxLayout>

namespace Ui {
class BaseDialog;
}

class BaseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BaseDialog(QWidget *parent = 0);
    ~BaseDialog();
    void setSubWidget(QWidget*);

private:
    Ui::BaseDialog *ui;
    bool leftBtnDown;
    QPoint ptMove;
    QPoint ptPressGlobal;

private:
    void initBaseDialog();
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseDoubleClickEvent(QMouseEvent *);
};

#endif // BASEDIALOG_H
