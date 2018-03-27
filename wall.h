#ifndef WALL_H
#define WALL_H

#include "object.h"
#include <GL/glu.h>

class Wall : public Object
{
public:
    Wall();

    // Destructeur
    virtual ~Wall();

    // Methode d'affichage
    virtual void Display();

private:
    float xHorizontal;
    float xVerticalGauche;
    float xVerticalDroite;
    float yDown;
    float yUp;
    float z;
    float size;
    GLUquadric* quadrique;
};

#endif // WALL_H
