
#include <GL/glu.h>
#include <QColor>
#include "object.h"


#include <QGLWidget>
#ifndef BALL_H
#define BALL_H
class Ball : public Object
{
public:
    Ball();

    // Destructeur
    virtual ~Ball();

    // Methode d'affichage
    virtual void Display();

private:

    float x;
    float y;
    float z;
    float size;
    GLUquadric* quadrique;


};

#endif // Ball_H



