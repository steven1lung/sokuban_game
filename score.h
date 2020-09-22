#ifndef SCORE_H
#define SCORE_H
#include<QGraphicsTextItem>
#include<QObject>
#include<QFont>
#include<QTimer>

class score : public QGraphicsTextItem
{
    Q_OBJECT
public:
    score();

    int score_=100;
    int step=0;
    //int get_score();
public slots:
    void increase();

};

#endif // SCORE_H
