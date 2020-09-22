#ifndef STAGE1_H
#define STAGE1_H

#include <QDialog>
#include <QLabel>
#include <QLabel>
#include <QString>
#include <QTextStream>
#include <QPixmap>
#include <QGraphicsScene>
#include <QMediaPlaylist>
#include <QGraphicsView>
#include <QScrollArea>
#include <QDebug>
#include <QMessageBox>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QKeyEvent>
#include <QMediaPlayer>
#include <QFile>
#include "winner.h"


namespace Ui {
class stage1;
}

class stage1 : public QDialog
{
    Q_OBJECT

public:
//

    explicit stage1(int choose,int design_count=0,QWidget *parent = nullptr);

    ~stage1();

    //know stage
    int stage;
    //put player.h in
    void keyPressEvent(QKeyEvent *event);
    QLabel *character;
    int score;
    int easter_egg=0;
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
    int best_score;
    bool score_added=0;


    QLabel *score_box;
    QLabel *wall[9][9];
    QLabel *hole;
    QLabel *background[9][9];
    QLabel *destination[3];
    QLabel *steps;
    QLabel *highest_score;

    //add sound
    QMediaPlayer *move_sound;
    QMediaPlayer *bgm;


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
    Ui::stage1 *ui;
};

#endif // STAGE1_H
