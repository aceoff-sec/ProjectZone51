#include "qstring.h"
#ifndef OBJECT_H
#define OBJECT_H


class Object
{
public:
    Object(QString name, int id);
    Object();
    virtual ~Object();
    virtual void Display();
    virtual void LoseLife();
    virtual float getInfo(QString value);
    virtual int getLife();
    virtual float getPoint();
    virtual QString getName();
    virtual int getId();

protected :



};

#endif // OBJECT_H
