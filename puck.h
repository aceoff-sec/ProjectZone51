#include <QGLWidget>
#include <GL/glu.h>
#include "object.h"

#ifndef Puck_H
#define Puck_H
class Puck : public Object
{
public:
    Puck();

    // Destructeur
    virtual ~Puck();

    // Methode d'affichage
    virtual void Display();
    //setter & getter
    void moveLeft();
    void moveRight();

private:

    float x;
    float y;
    float z;
    float size;
    GLUquadric* quadrique;


};

#endif // Puck_H

