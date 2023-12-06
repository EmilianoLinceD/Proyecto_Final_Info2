#ifndef PLATAFORMA1_H
#define PLATAFORMA1_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class plataforma1:public QObject,
                    public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    int x;
    int y;
public:
    plataforma1(QGraphicsItem* im1 = 0);
    void setX(int newX);
    void setY(int newY);
    int getX() const;
    int getY() const;
    void posicion();
    void posicion(int newX, int newY);
};

#endif // PLATAFORMA1_H
