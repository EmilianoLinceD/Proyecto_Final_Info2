#include "plataforma1.h"

plataforma1::plataforma1(QGraphicsItem *im):QGraphicsPixmapItem(im)
{
    setPixmap(QPixmap(":/images/piso1.jpg"));
}


void plataforma1::setX(int newX)
{
    x=newX;
}

void plataforma1::setY(int newY)
{
    y=newY;
}

int plataforma1::getX() const
{
    return x;
}

int plataforma1::getY() const
{
    return y;
}
void plataforma1::posicion()
{
    setPos(x,y);
}
void plataforma1::posicion(int newX, int newY)
{
    x=newX;
    y=newY;
    setPos(x,y);
}

