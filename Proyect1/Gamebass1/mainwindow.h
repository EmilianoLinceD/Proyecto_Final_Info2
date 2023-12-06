#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow> // Clase que incluye la ventana principal
#include <QGraphicsScene> // Manejo de gráficos
#include <QKeyEvent> // Captura de teclas
#include <QTimer>
#include "jugador1.h"
#include "jugador2.h"
#include "background.h"
#include "plataforma1.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void keyPressEvent(QKeyEvent *event);



private slots:
    void jmov();
    void fmov();
    void f2mov();
private:
    int velC=15; // velocidad de caida
    int vel=5; // pixceles que se va a mover
    int g=10; // valor equivalente a la gravedad
    int t=0; // valor equivalente al tiempo para ecuaciones
    //Valores equivalentes a los de una formula
    int m=30;
    int a=15;
    int k=15;
    Ui::MainWindow *ui;
    QGraphicsScene *scene; //escena para objetos gráficos e interacción
    Background *background;
    plataforma1 *plataformabas1;
    Jugador1 *jugador1;
    Jugador2 *jugador2;
    QTimer *timer1;
    QTimer *timer2;
    QTimer *timer3;

    QGraphicsPixmapItem *bgImage;
};
#endif // MAINWINDOW_H
