#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QDebug>
#include <QPixmap>
#include <QTimer>
#include <QFont>
#include <QGraphicsTextItem>
#include "box.h"

class player :public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    player();
    void keyPressEvent(QKeyEvent *event);
    int step=0;
    QGraphicsTextItem *step_show=new QGraphicsTextItem();
signals:
    void pressed();
public slots:
    void push();


};

#endif // PLAYER_H
