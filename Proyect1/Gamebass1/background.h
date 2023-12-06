#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Background:public QObject,
                   public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int x;
    int y;
public:
    Background(QGraphicsItem* im1 = 0);
    void setX(int newX);
    void setY(int newY);
    int getX() const;
    int getY() const;
    void posicion();
    void posicion(int newX, int newY);


};

#endif // BACKGROUND_H
