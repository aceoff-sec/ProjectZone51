#include <QGLWidget>
#include <GL/glu.h>
#include "object.h"
#include "string.h"
#include "qstring.h"
#ifndef Puck_H
#define Puck_H
class Puck : public Object
{
public:
    Puck(QString name, int id);

    // Destructeur
    virtual ~Puck();

    // Methode d'affichage
    virtual void Display();
    virtual float getInfo(QString value);
    virtual QString getName();
    virtual int getId();
    //setter & getter
    void moveLeft();
    void moveRight();


protected:

    float x;
    float y;
    float z;
    float size;
    GLUquadric* quadrique;
    float infox;
     float infoy;
    float infow;
     float infoh;
    QString name_;
    int id_;


};

#endif // Puck_H

