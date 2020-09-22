/*#ifndef STAGE2_H
#define STAGE2_H


#include "stage1.h"


namespace Ui {
class stage2;
}

class stage2 : public QDialog
{
    Q_OBJECT

public:
    explicit stage2(QWidget *parent = nullptr);
    ~stage2();


    //put player.h in
    void keyPressEvent(QKeyEvent *event);
    QLabel *character;
    int score=100;
    int step=0;
    QLabel *box[4];
    int box_show[9][12]={
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,2,0,0,0,0},
        {0,0,0,0,0,0,3,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0}
    };
    bool wall_show[9][12]={
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,1,1,1,1,1,1,0,0,0},
        {0,0,0,1,0,0,0,0,1,1,0,0},
        {0,0,0,1,0,0,0,0,0,1,0,0},
        {0,0,0,1,0,0,0,0,0,1,0,0},
        {0,0,0,1,1,1,1,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0}
    };
    int destination_show[6]={4,5,7,4,8,6};


    QLabel *wall[9][9];
    QLabel *hole;
    QLabel *background[9][9];
    QLabel *destination[3];

    //functions
    bool check_wall(int x,int y);
    bool check_box(int x,int y,int&n,int&r,int&c);
    bool check_win();

public slots:
    void score_decrease();
    void on_menu_button_clicked();
    void on_restart_butoon_clicked();
    void show_score_steps();

signals:
    void win();

private:
    Ui::stage2 *ui;
};

#endif // STAGE2_H
*/
