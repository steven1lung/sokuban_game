#ifndef WINNER_H
#define WINNER_H

#include <QDialog>
#include <QObject>
#include <QMovie>
#include "stage1.h"
#include "mainwindow.h"
#include "stage2.h"


namespace Ui {
class Winner;
}

class Winner : public QDialog
{
    Q_OBJECT

public:
    explicit Winner(int score,int step,int stage);
    ~Winner();
    QMovie *win1,*win2,*win3,*win4;
    int see_stage;
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Winner *ui;
};

#endif // WINNER_H
