#ifndef BOX_H
#define BOX_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class box: public QObject, public QGraphicsPixmapItem
{
public:
    box();
//public slots:
//    void pushed();
};

#endif // BOX_H
