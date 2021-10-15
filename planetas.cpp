#include "planetas.h"

Planetas::Planetas(float _posX, float _PosY, float _Radio, float _Vox, float _Voy, float _MasaSol, float _PxS, float _PyS)
{
    PosX=_posX;
    PosY=_PosY;
    Radio=_Radio;
    Vox=_Vox;
    Voy=_Voy;
    MasaSol= _MasaSol;
    PxS =_PxS;
    PyS = _PyS;

}

QRectF Planetas::boundingRect() const
{
    return QRectF(-Radio*Escala, -Radio*Escala, (Radio*2)*0.05, (Radio*2)*0.05);
}

void Planetas::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    //QPixmap pixMap(":/Mapa/Texturas/rompible.png");
    //pixMap = pixMap.scaled(Radio, Radio);
    //QRectF rectangulo(PosX*Escala, PosY*Escala, Radio*0.06, Radio*Escala);
    painter->drawEllipse(boundingRect());
    setPos(PosX*0.03, -PosY*0.03);
}

void Planetas::CalAngulo()
{


    Theta = (atan2((PyS-PosY),(PxS-PosX)));// * 180) / PI;

    RFormula = sqrt( (pow((PxS-PosX),2)) + (pow((PyS-PosY),2)) );

    AcX=(((GRAVEDAD * MasaSol) / pow(RFormula,2)) * cos(Theta));
    AcY=(((GRAVEDAD * MasaSol) / pow(RFormula,2)) * sin(Theta));

    VfX= Vox + AcX*Time;
    VfY = Voy + AcY*Time;



}

float Planetas::getVfX() const
{
    return VfX;
}


float Planetas::getVfY() const
{
    return VfY;
}


float Planetas::getAcX() const
{
    return AcX;
}


float Planetas::getAcY() const
{
    return AcY;
}


float Planetas::getPosX() const
{
    return PosX;
}

void Planetas::setPosX(float value)
{
    PosX = value;
}

float Planetas::getPosY() const
{
    return PosY;
}

void Planetas::setPosY(float value)
{
    PosY = value;
}

void Planetas::setVox(float value)
{
    Vox = value;
}

void Planetas::setVoy(float value)
{
    Voy = value;
}

void Planetas::setTime(int value)
{
    Time = value;
}
int Planetas::getTime() const
{
    return Time;
}

