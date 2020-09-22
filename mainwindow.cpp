#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("SOKOBAN");
    QMediaPlaylist *list=new QMediaPlaylist();
    list->setPlaybackMode(QMediaPlaylist::Loop);
    list->addMedia(QUrl("qrc:/img/sound/menu_bgm.mp3"));

    bgm=new QMediaPlayer();
    bgm->setPlaylist(list);
    bgm->setVolume(10);
    bgm->play();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    bgm->stop();
    hide();
    stage1 stage1(1,design_count);

//    stage1.destination[0]->move(350,200);
//    stage1.destination[1]->move(200,250);
//    stage1.destination[2]->move(400,300);
    stage1.setModal(true);
    stage1.exec();

}

void MainWindow::on_pushButton_2_clicked()
{
    hide();
    bgm->stop();
    stage1 stage2(2,design_count);
    stage2.setWindowTitle("SOKOBAN-Stage 2");
    stage2.setModal(true);
    stage2.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    bgm->stop();
    this->close();
}

void MainWindow::on_pushButton_4_clicked()
{
    hide();
    bgm->stop();
    stage1 stage3(3,design_count);
    stage3.setWindowTitle("SOKOBAN-Stage 3");
    stage3.setModal(true);
    stage3.exec();
}

void MainWindow::on_designButton_clicked()
{
    design_count++;
}
