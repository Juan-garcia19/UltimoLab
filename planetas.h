#ifndef PLANETAS_H
#define PLANETAS_H

#define Escala 0.03
#define PI 3.14159265
#define GRAVEDAD 1

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <math.h>

class Planetas : public QGraphicsItem
{
public:
    Planetas(float _posX, float _PosY, float _Radio, float _Vox, float _Voy, float _MasaSol, float _PxS, float _PyS);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

    void CalAngulo();



    float getVfX() const;

    float getVfY() const;

    float getAcX() const;

    float getAcY() const;

    int getTime() const;

    float getPosX() const;
    void setPosX(float value);

    float getPosY() const;
    void setPosY(float value);


    void setVox(float value);

    void setVoy(float value);

    void setTime(int value);

private:
    float PosX, PosY,PxS,PyS;
    float Radio,RFormula;
    float Vox,Voy;

    float MasaSol;
    float Theta;
    float AcX,AcY;
    float VfX,VfY;

    int Time=0;

};

#endif // PLANETAS_H
