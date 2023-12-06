#include "background.h"

Background::Background(QGraphicsItem *im):QGraphicsPixmapItem(im)
{
    setPixmap(QPixmap(":/images/background2.jpg"));
}


void Background::setX(int newX)
{
    x=newX;
}

void Background::setY(int newY)
{
    y=newY;
}

int Background::getX() const
{
    return x;
}

int Background::getY() const
{
    return y;
}
void Background::posicion()
{
    setPos(x,y);
}

void Background::posicion(int newX, int newY)
{
    x=newX;
    y=newY;
    setPos(x,y);
}
