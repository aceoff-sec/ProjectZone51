#include <QGLWidget>
#include <GL/glu.h>
#include "object.h"
#ifndef BRICK_H
#define BRICK_H


class brick: public Object
{
public:
    brick();
    // Destructeur
    virtual ~brick();

    // Methode d'affichage
    virtual void Display();
    //

    void setX(float X);
    void setY(float Y);
    float getX();
    float getY();
    int viechy();
private :
     float x;
    float y;
    float z;
    float size;
    int vie;
     GLUquadric* quadrique;
};

#endif // BRICK_H
