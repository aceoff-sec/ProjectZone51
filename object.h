#include "qstring.h"
#ifndef OBJECT_H
#define OBJECT_H


class Object
{
public:
    Object();
    virtual ~Object();
    virtual void Display();
    virtual void LoseLife();
    virtual float getInfo(QString value);
    virtual int getLife();
protected :



};

#endif // OBJECT_H
