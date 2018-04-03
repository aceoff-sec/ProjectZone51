#include <QGLWidget>
#include <GL/glu.h>
#include "object.h"
#include "qstring.h"
#ifndef BRICK_H
#define BRICK_H


class brick: public Object
{
public:
    brick(QString name, int id);
    // Destructeur
    virtual ~brick();

    // Methode d'affichage
    virtual void Display();
    //
    virtual void LoseLife();
    virtual float getInfo(QString value);
    virtual QString getName();
    virtual int getId();
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
     float infox;
      float infoy;
     float infow;
      float infoh;
     int id_;
     QString name_;

};

#endif // BRICK_H
