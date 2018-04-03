#ifndef WALL_H
#define WALL_H

#include "object.h"
#include <GL/glu.h>

class Wall : public Object
{
public:
    Wall(QString name, int id);

    // Destructeur
    virtual ~Wall();

    // Methode d'affichage
    virtual void Display();
    virtual QString getName();
    virtual int getId();

private:
    float xHorizontal;
    float xVerticalGauche;
    float xVerticalDroite;
    float yDown;
    float yUp;
    float z;
    float size;
    GLUquadric* quadrique;
    int id_;
    QString name_;
};

#endif // WALL_H
