#include "stage1.h"
#include "ui_stage1.h"
#include"mainwindow.h"

stage1::stage1(int choose,int design_count,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stage1)
{
    ui->setupUi(this);
    setWindowTitle("SOKOBAN-Stage 1");
    //connect
    connect(this,SIGNAL(win()),this,SLOT(show_score_steps()));
    stage=choose;

    if(design_count>=1)
        easter_egg=design_count;
    score=100+easter_egg;
    ui->score_label->setText(("SCORE : ")+QString::number(score));


    //add sound
    QMediaPlaylist *list=new QMediaPlaylist();
    list->setPlaybackMode(QMediaPlaylist::Loop);
    list->addMedia(QUrl("qrc:/img/sound/bmg.mp3"));

    move_sound=new QMediaPlayer();
    move_sound->setMedia(QUrl("qrc:/img/sound/siu.mp3"));
    bgm=new QMediaPlayer();
    bgm->setPlaylist(list);
    bgm->play();

    bgm->setVolume(10);
    move_sound->setVolume(10);

    //




    if(stage == 1 ){

        //set for stage 1




        //set background
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++){
                background[i][j]=new QLabel(this);
                background[i][j]->setPixmap(QPixmap(":/img/img/background.png").scaled(50,50));
                background[i][j]->move(150+50*i,50*j);
            }

        //set destination
        for(int i=0;i<3;i++){
            destination[i]= new QLabel(this);
            destination[i]->setPixmap(QPixmap(":/img/img/destination.png").scaled(50,50));
        }

        //add win_box
        score_box= new QLabel(this);
        score_box->setPixmap(QPixmap(":/img/img/slipper.png"));
        score_box->move(300,250);

        //add goal
        destination[0]->move(350,200);
        destination[1]->move(200,250);
        destination[2]->move(400,300);
        //add boxes
        for(int i=1;i<4;i++){
            box[i]=new QLabel(this);
            box[i]->setPixmap(QPixmap(":/img/img/egg.png").scaled(50,50));
        }
        box[1]->move(250,200);
        box[2]->move(350,250);
        box[3]->move(300,300);

        //add walls
        for(int i=0;i<9;i++)
            for(int j=0;j<12;j++)
                if(wall_show[i][j]==1){
                    wall[i][j]=new QLabel(this);
                    wall[i][j]->setPixmap(QPixmap(":/img/img/wall.png").scaled(50,50));
                    wall[i][j]->move(50*j,50*i);
                }



    }
    else if(stage == 2){
        //set for stage 2


        //set box
        int box_show2[9][12]={
            {0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,1,0,0},
            {0,0,0,0,0,0,0,0,0,2,0,0},
            {0,0,0,0,0,0,0,0,0,3,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0}
        };
        for(int i=0;i<9;i++)
            for(int j=0;j<12;j++)
                box_show[i][j]=box_show2[i][j];


        //set wall
        bool wall_show2[9][12]={
            {0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,1,1,1,1,1,1,1,1,1},
            {0,0,0,1,0,0,0,0,1,0,0,1},
            {0,0,0,1,0,1,0,0,1,0,0,1},
            {0,0,0,1,0,0,0,0,0,0,0,1},
            {0,0,0,1,0,1,0,0,1,0,0,1},
            {0,0,0,1,0,0,0,0,1,0,0,1},
            {0,0,0,1,1,1,1,1,1,0,0,1},
            {0,0,0,0,0,0,0,0,1,1,1,1}
        };
        for(int i=0;i<9;i++)
            for(int j=0;j<12;j++)
                wall_show[i][j]=wall_show2[i][j];


        //set background
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++){
                background[i][j]=new QLabel(this);
                background[i][j]->setPixmap(QPixmap(":/img/img/background.png").scaled(50,50));
                background[i][j]->move(150+50*i,50*j);
            }



        //add walls
        for(int i=0;i<9;i++)
            for(int j=0;j<12;j++)
                if(wall_show[i][j]==1){
                    wall[i][j]=new QLabel(this);
                    wall[i][j]->setPixmap(QPixmap(":/img/img/wall.png").scaled(50,50));
                    wall[i][j]->move(50*j,50*i);
                }



        //set destination
        for(int i=0;i<3;i++){
            destination[i]= new QLabel(this);
            destination[i]->setPixmap(QPixmap(":/img/img/destination.png").scaled(50,50));
            destination[i]->move(500,150+50*i);
        }
//        qDebug()<<destination[0]->x()<<destination[0]->y();
//        qDebug()<<destination[1]->x()<<destination[1]->y();
//        qDebug()<<destination[2]->x()<<destination[2]->y();

        int destination_show2[6]={10,3,10,4,10,5};
        for(int i=0;i<6;i++)
            destination_show[i]=destination_show2[i];



        //add win_box
        score_box= new QLabel(this);
        score_box->setPixmap(QPixmap(":/img/img/slipper.png"));
        score_box->move(300,250);

        //add boxes
        for(int i=1;i<4;i++){
            box[i]=new QLabel(this);
            box[i]->setPixmap(QPixmap(":/img/img/egg.png").scaled(50,50));
            box[i]->move(450,100+50*i);
        }
    }
    else{
        //stage 3

        //set box
        int box_show2[9][12]={
            {0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,1,0,0,0},
            {0,0,0,0,0,2,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,3,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0}
        };
        for(int i=0;i<9;i++)
            for(int j=0;j<12;j++)
                box_show[i][j]=box_show2[i][j];


        //set wall
        bool wall_show2[9][12]={
            {0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,1,1,1,1,1,1,1,1,0},
            {0,0,0,1,0,0,0,0,0,0,1,0},
            {0,0,0,1,0,0,0,0,1,0,1,0},
            {0,0,0,1,0,1,0,1,0,0,1,0},
            {0,0,0,1,1,1,0,1,0,1,1,0},
            {0,0,0,0,1,0,0,0,0,1,0,0},
            {0,0,0,0,1,0,0,1,1,1,0,0},
            {0,0,0,0,1,1,1,1,0,0,0,0}

        };
        for(int i=0;i<9;i++)
            for(int j=0;j<12;j++)
                wall_show[i][j]=wall_show2[i][j];


        //set background
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++){
                background[i][j]=new QLabel(this);
                background[i][j]->setPixmap(QPixmap(":/img/img/background.png").scaled(50,50));
                background[i][j]->move(150+50*i,50*j);
            }



        //add walls
        for(int i=0;i<9;i++)
            for(int j=0;j<12;j++)
                if(wall_show[i][j]==1){
                    wall[i][j]=new QLabel(this);
                    wall[i][j]->setPixmap(QPixmap(":/img/img/wall.png").scaled(50,50));
                    wall[i][j]->move(50*j,50*i);
                }



        //set destination
        for(int i=0;i<3;i++){
            destination[i]= new QLabel(this);
            destination[i]->setPixmap(QPixmap(":/img/img/destination.png").scaled(50,50));
            destination[i]->move(200,100+50*i);
        }
//        qDebug()<<destination[0]->x()<<destination[0]->y();
//        qDebug()<<destination[1]->x()<<destination[1]->y();
//        qDebug()<<destination[2]->x()<<destination[2]->y();

        int destination_show2[6]={4,2,4,3,4,4};
        for(int i=0;i<6;i++)
            destination_show[i]=destination_show2[i];



        //add win_box
        score_box= new QLabel(this);
        score_box->setPixmap(QPixmap(":/img/img/slipper.png"));
        score_box->move(300,250);


        //add boxes
        for(int i=1;i<4;i++){
            box[i]=new QLabel(this);
            box[i]->setPixmap(QPixmap(":/img/img/egg.png").scaled(50,50));

        }
        box[1]->move(400,100);
        box[2]->move(250,150);
        box[3]->move(300,300);



    }






    //add player
    character= new QLabel(this);
    character->setPixmap(QPixmap(":/img/img/AB.png").scaled(50,50));
    if(stage==1)
        character->move(350,300);
    else if (stage==2 ){
        character->move(450,350);

    }
    else {
        //stage 3
        character->move(250,350);
    }


    //ui->score_label->setText(("SCORE : ")+QString::number(score));

    //score countdown
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(score_decrease()));

    timer->start(1000);

    //add step to top right and highest score
    //steps=new QLabel(this);
    ui->score_label_2->setText("STEPS : "+QString::number(step));
   // steps->setGeometry(500,20,100,50);

    if(stage==1){
        QFile stage1_best("/home/pd2/2020-pd2-sokoban/stage1_score.txt");
        stage1_best.open(QIODevice::ReadOnly);
        QTextStream in(&stage1_best);
        QString best = in.readLine();
        best_score=best.toInt();
        //highest_score=new QLabel(this);
        stage1_best.close();
        ui->score_label_3->setText("BEST : "+best);
        //highest_score->setGeometry(500,0,100,50);
        /*stage1_best.open(QIODevice::WriteOnly | QIODevice::Truncate);
        QTextStream out(&stage1_best);
        out << "192" << endl;
        stage1_best.close();*/
    }
    else if (stage==2){

        QFile stage1_best("/home/pd2/2020-pd2-sokoban/stage2_score.txt");
        stage1_best.open(QIODevice::ReadOnly);
        QTextStream in(&stage1_best);
        QString best = in.readLine();
        best_score=best.toInt();
        //highest_score=new QLabel(this);
        stage1_best.close();
        ui->score_label_3->setText("BEST : "+best);
        //highest_score->setGeometry(500,0,100,50);
    }
    else{
        QFile stage1_best("/home/pd2/2020-pd2-sokoban/stage3_score.txt");
        stage1_best.open(QIODevice::ReadOnly);
        QTextStream in(&stage1_best);
        QString best = in.readLine();
        best_score=best.toInt();
        //highest_score=new QLabel(this);
        stage1_best.close();
        ui->score_label_3->setText("BEST : "+best);
        //highest_score->setGeometry(500,0,100,50);
    }









//     emit win();



}

stage1::~stage1()
{
    delete ui;
}

void stage1::keyPressEvent(QKeyEvent *event)
{
    move_sound->play();
    if(event->key()==Qt::Key_Left){
        int box_num=0,x=0,y=0;
        if(check_box(character->x()-50,character->y(),box_num,x,y)){
//            qDebug()<<"push box"<<x<<y;
            if(!check_wall(box[box_num]->x()-50,box[box_num]->y())&&!check_box(box[box_num]->x()-50,box[box_num]->y(),box_num,x,y) ){
                box[box_num]->move(box[box_num]->x()-50,box[box_num]->y());
                box_show[y][x]=0;
                box_show[y][x-1]=box_num;
                character->move(character->x()-50,character->y());
                if(!score_added&&character->x()==300&&character->y()==250){
                    score+=10;
                    ui->score_label->setText(("SCORE : ")+QString::number(score));
                    score_added=1;
                    delete score_box;

                }
                step++;
            }
        }
        else if(!check_wall(character->x()-50,character->y())){
//
            character->move(character->x()-50,character->y());
            if(!score_added&&character->x()==300&&character->y()==250) {
                score+=10;
                ui->score_label->setText(("SCORE : ")+QString::number(score));
                score_added=1;
                delete score_box;

            }
            step++;
        }

    }
    if(event->key()==Qt::Key_Right){
        int box_num=0,x=0,y=0;
        if(check_box(character->x()+50,character->y(),box_num,x,y)){
//            qDebug()<<"push box"<<x<<y;
            if(!check_wall(box[box_num]->x()+50,box[box_num]->y())&&!check_box(box[box_num]->x()+50,box[box_num]->y(),box_num,x,y)) {
                box[box_num]->move(box[box_num]->x()+50,box[box_num]->y());
                box_show[y][x]=0;
                box_show[y][x+1]=box_num;
                character->move(character->x()+50,character->y());
                if(!score_added&&character->x()==300&&character->y()==250){
                    score+=10;
                    ui->score_label->setText(("SCORE : ")+QString::number(score));
                    score_added=1;
                    delete score_box;

                }
                step++;
            }
        }
        else if(!check_wall(character->x()+50,character->y())){
//
            character->move(character->x()+50,character->y());
            if(!score_added&&character->x()==300&&character->y()==250) {
                score+=10;
                ui->score_label->setText(("SCORE : ")+QString::number(score));
                score_added=1;
                delete score_box;

            }
            step++;
        }
    }
    if(event->key()==Qt::Key_Up){
        int box_num=0,x=0,y=0;
        if(check_box(character->x(),character->y()-50,box_num,x,y)){
//            qDebug()<<"push box"<<x<<y;
            if(!check_wall(box[box_num]->x(),box[box_num]->y()-50)&&!check_box(box[box_num]->x(),box[box_num]->y()-50,box_num,x,y)) {
                box[box_num]->move(box[box_num]->x(),box[box_num]->y()-50);
                box_show[y][x]=0;
                box_show[y-1][x]=box_num;
                character->move(character->x(),character->y()-50);
                //add this if
                if(!score_added&&character->x()==300&&character->y()==250){
                    score+=10;
                    ui->score_label->setText(("SCORE : ")+QString::number(score));
                    score_added=1;
                    delete score_box;

                }
                step++;
            }
        }
        else if(!check_wall(character->x(),character->y()-50)){
//
            character->move(character->x(),character->y()-50);
            //add this if
            if(!score_added&&character->x()==300&&character->y()==250) {
                score+=10;
                ui->score_label->setText(("SCORE : ")+QString::number(score));
                score_added=1;
                delete score_box;

            }
            step++;
        }
    }
    if(event->key()==Qt::Key_Down){
        int box_num=0,x=0,y=0;
        if(check_box(character->x(),character->y()+50,box_num,x,y)){
//            qDebug()<<"push box"<<x<<y;
            if(!check_wall(box[box_num]->x(),box[box_num]->y()+50)&&!check_box(box[box_num]->x(),box[box_num]->y()+50,box_num,x,y)) {
                box[box_num]->move(box[box_num]->x(),box[box_num]->y()+50);
                box_show[y][x]=0;
                box_show[y+1][x]=box_num;
                character->move(character->x(),character->y()+50);
                if(!score_added&&character->x()==300&&character->y()==250){
                    score+=10;
                    ui->score_label->setText(("SCORE : ")+QString::number(score));
                    score_added=1;
                    delete score_box;

                }
                step++;
            }
        }
        else if(!check_wall(character->x(),character->y()+50)){
//
            character->move(character->x(),character->y()+50);
            if(!score_added&&character->x()==300&&character->y()==250) {
                score+=10;
                ui->score_label->setText(("SCORE : ")+QString::number(score));
                score_added=1;
                delete score_box;

            }
            step++;
        }
    }
    ui->score_label_2->setText("STEPS : "+QString::number(step));
    //qDebug()<<step;

    //check if win

    if(check_win()){
        emit win();

    }





}

bool stage1::check_wall(int x, int y)
{
    int x_check=x/50,y_check=y/50;
    if(wall_show[y_check][x_check]==1){
        //qDebug()<<"hit "<<x_check<<y_check;
        return 1;
    }
    else return 0;
}

bool stage1::check_box(int x, int y,int &n,int &r,int &c)
{
    int x_check=x/50,y_check=y/50;
    if(box_show[y_check][x_check]){
        //qDebug()<<y_check<<x_check;
        n=box_show[y_check][x_check];r=x_check;c=y_check;
        return 1;
    }
    else return 0;
}

bool stage1::check_win()
{
    int a,b,c;
    for(int i=0;i<3;i++){
        int x=destination_show[2*i]*50,y=destination_show[2*i+1]*50;
        if(check_box(x,y,a,b,c)==0){
        //    qDebug()<<"not win";
            return 0;
        }

    }
    //qDebug()<<"win";
    return 1;
}

void stage1::score_decrease()
{
    score-=1;
    ui->score_label->setText(("SCORE : ")+QString::number(score));
}


void stage1::on_menu_button_clicked()
{
    bgm->stop();
    this->close();
    MainWindow *w=new MainWindow();
    w->show();
    w->setFixedSize(811,550);

}

void stage1::on_restart_butoon_clicked()
{
    bgm->stop();
    if(stage==1){
        this->close();
        stage1 *stage1=new class stage1(1);
        stage1->show();
    }
    else if (stage==2){
        this->close();
//        stage1 stage2(2);
//        stage2.setWindowTitle("SOKUBAN-Stage 2");
//        stage2.show();
        stage1 *stage2=new class stage1(2);
        stage2->show();
    }
    else{
        this->close();
        stage1 *stage3=new class stage1(3);
        stage3->show();
    }
}

void stage1::show_score_steps()
{
    int stop_score=score;
    bgm->stop();
    this->close();
    Winner win(stop_score,step,stage);
    win.setModal(true);
    win.exec();

    if(stage==1){
        if(stop_score>=best_score){
            QFile stage1_best("/home/pd2/2020-pd2-sokoban/stage1_score.txt");
            stage1_best.open(QIODevice::WriteOnly | QIODevice::Truncate);
            QTextStream out(&stage1_best);
            out << stop_score << endl;
            stage1_best.close();
        }
    }
    else if (stage==2){
        if(stop_score>=best_score){
            QFile stage1_best("/home/pd2/2020-pd2-sokoban/stage2_score.txt");
            stage1_best.open(QIODevice::WriteOnly | QIODevice::Truncate);
            QTextStream out(&stage1_best);
            out << stop_score << endl;
            stage1_best.close();
        }
    }
    else{
        if(stop_score>=best_score){
            QFile stage1_best("/home/pd2/2020-pd2-sokoban/stage3_score.txt");
            stage1_best.open(QIODevice::WriteOnly | QIODevice::Truncate);
            QTextStream out(&stage1_best);
            out << stop_score << endl;
            stage1_best.close();
        }
    }
}
