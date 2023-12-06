#ifndef JUGADOR2_H
#define JUGADOR2_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Jugador2:public QObject,
                 public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int x;
    int y;
    bool flag=true;
    int cont=0;
public:
    Jugador2(QGraphicsItem* im1 = 0);
    void setX(int newX);
    void setY(int newY);
    int getX() const;
    int getY() const;

    //Definir posicion graficar
    void posicion();
    void posicion(int newX, int newY);
    //Simular caminar
    void mov();
};

#endif // JUGADOR1_H
