#include "winner.h"
#include "ui_winner.h"

Winner::Winner(int score,int steps,int stage) :
    QDialog(),
    ui(new Ui::Winner)
{
    see_stage=stage;
    ui->setupUi(this);
    setWindowTitle("YOU HAVE WON");


    //add gif1
    win1= new QMovie(":/img/img/midwind.gif");
    QLabel *la=new QLabel(this);
    la->setGeometry(280,0,120,120);

    la->setMovie(win1);
    win1->setScaledSize(la->size());

    win1->start();
    //add gif2
    win2=new QMovie(":/img/img/hasake.gif");
    QLabel *la1=new QLabel(this);
    la1->setGeometry(300,200,100,100);
    la1->setMovie(win2);
    win2->setScaledSize(la1->size());
    win2->start();
    //

    //add gif3
    win3=new QMovie(":/img/img/learndarius.gif");
    QLabel *la2=new QLabel(this);
    la2->setGeometry(0,0,100,100);
    la2->setMovie(win3);
    win3->setScaledSize(la2->size());
    win3->start();

    //add gif4
    win4=new QMovie(":/img/img/bear.gif");
    QLabel *la3=new QLabel(this);
    la3->setGeometry(0,200,100,100);
    la3->setMovie(win4);
    win4->setScaledSize(la3->size());
    win4->start();



    //
    ui->score->setText("SCORE : "+QString::number(score));
    ui->steps->setText("STEPS : "+QString::number(steps));
    if(stage==3){
        delete ui->pushButton;
    }
}

Winner::~Winner()
{
    delete ui;
}

void Winner::on_pushButton_2_clicked()
{
    this->close();
    MainWindow *w=new MainWindow();
    w->show();
    w->setFixedSize(811,550);

}

void Winner::on_pushButton_clicked()
{
    this->close();
    if(see_stage==1){
        stage1 stage2(2);
        stage2.setWindowTitle("SOKOBAN-Stage 2");
        stage2.setModal(true);
        stage2.exec();
    }
    else if (see_stage==2){
        stage1 stage3(3);
        stage3.setWindowTitle("SOKOBAN-Stage 3");
        stage3.setModal(true);
        stage3.exec();
    }
}
