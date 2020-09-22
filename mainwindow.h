#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QLabel>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "stage1.h"
#include "stage2.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QMediaPlayer *bgm;
    QLabel *bg;
    int design_count=0;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_designButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
