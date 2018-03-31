
#include <GL/glu.h>
#include <QColor>
#include "object.h"


#include <QGLWidget>
#ifndef BALL_H
#define BALL_H
class Ball : public Object
{
public:
    Ball(float Xb,float Yb,float Larg);

    // Destructeur
    virtual ~Ball();

    // Methode d'affichage
    virtual void Display();
    virtual void LoseLife();
    //Modification position
    void setPos();
    float getX();
    float getY();
    float getR();
    float getdx();
    float getdy();
    void setdx(float x_);
    void setdy(float y_);

private:

    float x;
    float y;
    float z;
    float size;
    int vie;
    int dx;
    int dy;
    GLUquadric* quadrique;


};

#endif // Ball_H



