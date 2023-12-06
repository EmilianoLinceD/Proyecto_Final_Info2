#include "jugador1.h"

Jugador1::Jugador1(QGraphicsItem* im):QGraphicsPixmapItem(im)
{
    setPixmap(QPixmap(":/images/rick.png"));
}
//Simulacion de caminar
void Jugador1::mov()
{
    if (cont<5)
    {
        setPixmap(QPixmap(":/images/rick.png"));
        //flag=false;
    }
    if (cont==5)cont=0;

    cont++;

}
void Jugador1::setX(int newX)
{
    x = newX;
}

int Jugador1::getX() const
{
    return x;
}

int Jugador1::getY() const
{
    return y;
}

void Jugador1::setY(int newY)
{
    y = newY;
}

//Definir posicion en la grafica
void Jugador1::posicion()
{
    setPos(x,y);
}

void Jugador1::posicion(int newX, int newY)
{
    x=newX;
    y=newY;
    setPos(x,y);
}
