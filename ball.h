
#include <GL/glu.h>
#include <QColor>
#include "object.h"


#include <QGLWidget>
#ifndef BALL_H
#define BALL_H
class Ball : public Object
{
public:
    Ball(float Xb,float Yb,float Larg, int id);

    // Destructeur
    virtual ~Ball();

    // Methode d'affichage
    virtual void Display();
    virtual void LoseLife();
    virtual int getLife();
    //Modification position
    void setPos();
    float getX();
    float getY();
    float getR();
    float getdx();
    float getdy();
    void setdx(float x_);
    void setdy(float y_);
    void setx(float x_) { x = x_; }
    void sety(float y_) { y = y_; }
    virtual int getId() {return id_;}

private:

    float x;
    float y;
    float z;
    float size;
    int vie;
    float dx;
    float dy;
    GLUquadric* quadrique;
    int id_;
    int val_;


};

#endif // Ball_H



