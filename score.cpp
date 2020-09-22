#include "score.h"


score::score()//QGraphicsTextItem ()
{

    //draw text
    setPlainText((QString("SCORE : ")+QString::number(score_)));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
    QTimer * timer=new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(increase()));

    timer->start(5000);
}

void score::increase()
{
    score_-=1;

    setPlainText((QString("SCORE : ")+QString::number(score_)));
}

