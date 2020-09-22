/*#include "stage2.h"
#include "ui_stage2.h"
#include"mainwindow.h"

stage2::stage2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stage2)
{
    setWindowTitle("SOKUBAN-Stage 1");
    //connect
    connect(this,SIGNAL(win()),this,SLOT(show_score_steps()));
    //
    //emit win();




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
    destination[0]->move(350,200);
    destination[1]->move(200,250);
    destination[2]->move(400,300);


    //add player
    character= new QLabel(this);
    character->setPixmap(QPixmap(":/img/img/AB.png").scaled(50,50));
    character->move(350,300);


    //problem below
    //ui->score_label->setText(("SCORE : ")+QString::number(score));


    //score countdown
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(score_decrease()));

    timer->start(1000);
    //



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

stage2::~stage2()
{
    delete ui;
}

void stage2::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Left){
        int box_num=0,x=0,y=0;
        if(check_box(character->x()-50,character->y(),box_num,x,y)){
//            qDebug()<<"push box"<<x<<y;
            if(!check_wall(box[box_num]->x()-50,box[box_num]->y())&&!check_box(box[box_num]->x()-50,box[box_num]->y(),box_num,x,y) ){
                box[box_num]->move(box[box_num]->x()-50,box[box_num]->y());
                box_show[y][x]=0;
                box_show[y][x-1]=box_num;
                character->move(character->x()-50,character->y());
                step++;
            }
        }
        else if(!check_wall(character->x()-50,character->y())){
//
            character->move(character->x()-50,character->y());
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
                step++;
            }
        }
        else if(!check_wall(character->x()+50,character->y())){
//
            character->move(character->x()+50,character->y());
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
                step++;
            }
        }
        else if(!check_wall(character->x(),character->y()-50)){
//
            character->move(character->x(),character->y()-50);
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
                step++;
            }
        }
        else if(!check_wall(character->x(),character->y()+50)){
//
            character->move(character->x(),character->y()+50);
            step++;
        }
    }
    //qDebug()<<step;

    //check if win

    if(check_win()){
        emit win();
    }





}

bool stage2::check_wall(int x, int y)
{
    int x_check=x/50,y_check=y/50;
    if(wall_show[y_check][x_check]==1){
        //qDebug()<<"hit "<<x_check<<y_check;
        return 1;
    }
    else return 0;
}

bool stage2::check_box(int x, int y,int &n,int &r,int &c)
{
    int x_check=x/50,y_check=y/50;
    if(box_show[y_check][x_check]){
        //qDebug()<<y_check<<x_check;
        n=box_show[y_check][x_check];r=x_check;c=y_check;
        return 1;
    }
    else return 0;
}

bool stage2::check_win()
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

void stage2::score_decrease()
{
    score-=1;
    ui->score_label->setText(("SCORE : ")+QString::number(score));
}


void stage2::on_menu_button_clicked()
{
    this->close();
    MainWindow *w=new MainWindow();
    w->show();
    w->setFixedSize(811,550);

}

void stage2::on_restart_butoon_clicked()
{
    this->close();
    stage2 *stage2=new class stage2();
    stage2->show();
}

void stage2::show_score_steps()
{
    this->close();
    Winner win(score,step);
    win.setModal(true);
    win.exec();
}
*/
