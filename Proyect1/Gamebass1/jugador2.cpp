#include "jugador2.h"

Jugador2::Jugador2(QGraphicsItem* im):QGraphicsPixmapItem(im)
{
    setPixmap(QPixmap(":/images/rick.png"));
}
//Simulacion de caminar
void Jugador2::mov()
{
    if (cont<5)
    {
        setPixmap(QPixmap(":/images/rick.png"));
        //flag=false;
    }
    if (cont==5)cont=0;

    cont++;

}
void Jugador2::setX(int newX)
{
    x = newX;
}

int Jugador2::getX() const
{
    return x;
}

int Jugador2::getY() const
{
    return y;
}

void Jugador2::setY(int newY)
{
    y = newY;
}

//Definir posicion en la grafica
void Jugador2::posicion()
{
    setPos(x,y);
}

void Jugador2::posicion(int newX, int newY)
{
    x=newX;
    y=newY;
    setPos(x,y);
}

