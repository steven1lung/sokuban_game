#include "player.h"


player::player(){
    setPixmap(QPixmap(":/img/img/AB.png"));
    step_show->setPlainText((QString("STEPS : ")+QString::number(step)));
    step_show->setDefaultTextColor(Qt::red);
    step_show->setFont(QFont("times",16));
}



void player::keyPressEvent(QKeyEvent *event)
{

    step++;
    if(event->key()==Qt::Key_Left){
        if(pos().x()>0)
        setPos(x()-40,y());
        emit pressed();
    }
    if(event->key()==Qt::Key_Right){
        if(pos().x()+50<500)
        setPos(x()+40,y());
        emit pressed();
    }
    if(event->key()==Qt::Key_Down){
        if(pos().y()<450)
        setPos(x(),y()+40);
        emit pressed();
    }
    if(event->key()==Qt::Key_Up){
        if(pos().y()>0)
        setPos(x(),y()-40);
        emit pressed();
    }
    connect(this,SIGNAL(pressed()),this,SLOT(push()));

}

void player::push()
{
    //if player collides with box , move both
    QList<QGraphicsItem *> colliding= collidingItems();
    for(int i=0,n=colliding.size();i<n;i++){
        if(typeid (*(colliding[i]))==typeid (box)){
            //push item with same direction
            qDebug()<<"push";
        }
    }
}
