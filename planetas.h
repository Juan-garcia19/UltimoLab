#ifndef PLANETAS_H
#define PLANETAS_H

#define Escala 0.03
#define PI 3.14159265

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <math.h>

class Planetas : public QGraphicsItem
{
public:
    Planetas(int _posX, int _PosY, int _Radio, int _Vox, int _Voy, int _MasaSol,int _PxS, int _PyS);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

    void CalAngulo();



private:
    int PosX, PosY,PxS,PyS;
    int Radio,RFormula;
    int Vox,Voy;
    int MasaSol;
    int Theta;

};

#endif // PLANETAS_H
