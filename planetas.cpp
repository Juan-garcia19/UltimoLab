#include "planetas.h"

Planetas::Planetas(int _posX, int _PosY, int _Radio, int _Vox, int _Voy, int _MasaSol, int _PxS, int _PyS)
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
    return QRectF(PosX*0.03, PosY*0.03, Radio, Radio);
}

void Planetas::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    //QPixmap pixMap(":/Mapa/Texturas/rompible.png");
    //pixMap = pixMap.scaled(Radio, Radio);
    QRectF rectangulo(PosX*Escala, PosY*Escala, Radio*Escala, Radio*Escala);
    painter->drawEllipse(rectangulo);
}

void Planetas::CalAngulo()
{
    Theta = atan2((PosY-PyS),(PosX-PxS)) * 180 / PI;

    RFormula = sqrt( (pow((PosX-PxS),2)) + (pow((PosY-PyS),2)) );


}
