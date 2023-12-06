#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{

    ui->setupUi(this);

    auto scene = new QGraphicsScene();    //Definir Escena para montar la "obra"
    scene->setSceneRect(0,0,5500,3143); //Definir los limites de la escena
    scene->setSceneRect(ui->graphicsView->rect());
    ui->graphicsView->setScene(scene); //Dar la escena al graphics
    scene->addRect(scene->sceneRect()); //Dibujar cuadrado de la escena

    background = new Background();
    background->posicion(0,0);
    scene->addItem(background);

    plataformabas1 = new plataforma1();
    plataformabas1->posicion(0,550);
    scene->addItem(plataformabas1);

    jugador1 = new Jugador1();
    jugador1->posicion(250,250);
    scene->addItem(jugador1);

    jugador2 = new Jugador2();
    jugador2->posicion(400,500-10);
    scene->addItem(jugador2);

    timer1 = new QTimer;
    connect(timer1,SIGNAL(timeout()),this,SLOT(jmov()));
    timer1->stop();
    //timer->start(1000);

    timer2 = new QTimer;
    connect(timer2,SIGNAL(timeout()),this,SLOT(fmov()));
    timer2->start(60);

    timer3 = new QTimer;
    connect(timer3,SIGNAL(timeout()),this,SLOT(f2mov()));
    timer3->start(60);


}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete background;
    delete jugador1;
    delete jugador2;
    delete timer1;
    delete timer2;
    delete timer3;
    delete bgImage;

}

//Funcion de teclas
void MainWindow::keyPressEvent(QKeyEvent *event){       //Funciones de teclas

    switch (event->key()) {
    case Qt::Key_F4:
        close();
        break;
    case Qt::Key_D:
        if(jugador1->getX()>(1000-36)) jugador1->posicion(0,jugador1->getY());
        if(jugador1->getX()==jugador2->getX() && jugador1->getY() ==jugador2->getY()){

            delete jugador1;
            //jugador1->posicion(0,jugador1->getY());

        }
        jugador1->setX(jugador1->getX()+vel);
        jugador1->mov();
        jugador1->posicion();

        break;
    case Qt::Key_A:
         if(jugador1->getX()==jugador2->getX() && jugador1->getY() ==jugador2->getY()) jugador1->posicion(0,jugador1->getY());
        jugador1->setX(jugador1->getX()-vel);
        jugador1->mov();
        jugador1->posicion();
        break;
    case Qt::Key_W:
         if(jugador1->getX()==jugador2->getX() && jugador1->getY() ==jugador2->getY()) jugador1->posicion(0,jugador1->getY());
        jugador1->setY(jugador1->getY()-vel);
        jugador1->mov();
        jugador1->posicion();

        break;
    case Qt::Key_S:
        jugador1->setY(jugador1->getY()+vel);
        jugador1->mov();
        jugador1->posicion();
        break;

    default:
        break;
    }


//    if(event->key()==Qt::Key_F4) close();

//    if(event->key()==Qt::Key_D ){

//    if(jugador1->getX()>(500-36)) jugador1->posicion(0,jugador1->getY());
//          jugador1->setX(jugador1->getX()+vel);

//    }

//    if(event->key()==Qt::Key_A){
//        jugador1->setX(jugador1->getX()-vel);
//    }

//    if(event->key()==Qt::Key_W){
//        jugador1->setY(jugador1->getY()-vel);
//    }

//    if(event->key()==Qt::Key_S){
//        jugador1->setY(jugador1->getY()+vel);
//    }


//    if(event->key()==Qt::Key_L){
//        if(jugador2->getX()>(500-36)) jugador2->posicion(0,jugador2->getY());
//        jugador2->setX(jugador2->getX()+vel);
//    }

//    if(event->key()==Qt::Key_J){
//        jugador2->setX(jugador2->getX()-vel);
//    }

//    if(event->key()==Qt::Key_I){
//        jugador2->setY(jugador2->getY()-vel);
//    }

//    if(event->key()==Qt::Key_K){
//        jugador2->setY(jugador2->getY()+vel);
//    }

//    jugador1->mov();
//      jugador1->posicion();
//    jugador2->mov();
    //    jugador2->posicion();
}

void MainWindow::jmov()
{
    //if(jugador1->getX()>(1000-36)) jugador1->posicion(0,jugador1->getY());
 ;
//    if(jugador2->getX()>(500-36)) jugador2->posicion(0,jugador2->getY());
//    jugador2->setX(jugador2->getX()+1);
//    jugador2->posicion();
    //if(jugador1->getX()==jugador2->getX() && jugador1->getY() ==jugador2->getY()) jugador1->posicion(0,jugador1->getY());


}

void MainWindow::fmov()
{


    //Y=vel*t+(1/2)*g*(t*t);  formula tiro vertical o parabolico formula para salto del jugador.
    // -g hacia arriba.
    // +g hacia abajo.
    // tenemos dos formulas entonces, una es para caida libre y la otra si ya es para tiro vertical.

 //   if(jugador1->getY()>=(500-10)){ jugador1->posicion(jugador1->getX(),500-10);}
 //   else{

 //       jugador1->setY(jugador1->getY()+velC+((1/2)*g));
 //       jugador1->posicion();

 //   }

    if(jugador1->collidesWithItem(plataformabas1)){
        jugador1->posicion(jugador1->getX(),(plataformabas1->getY())-30);
        t=0;}
       else{

        jugador1->setY(jugador1->getY()+velC*t+((1/2)*g)*(t*t));
        jugador1->posicion();
        t++;
    }



    //Futura formula de aplicacion de fuerzas, plano inclinado.
}

void MainWindow::f2mov()
{
    //X=(m*a)/k;   formula elsticidad para rebote en paredes.


    if(jugador1->getX()>=(500-10)){
        jugador1->setX(jugador1->getX()-(m*a)/k);
        jugador1->posicion();
    }else if(jugador1->getX()<=0){
        jugador1->setX(jugador1->getX()+(m*a)/k);
        jugador1->posicion();
    }

}

//QBoundingRect


