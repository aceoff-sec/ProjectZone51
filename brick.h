#include <QGLWidget>
#include <GL/glu.h>
#include "object.h"
#include "qstring.h"
#ifndef BRICK_H
#define BRICK_H


class brick: public Object
{
public:
    brick(QString name, int id, QImage imb);
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
    void setR(float R_) { R = R_; }
    void setV(float V_) { V = V_; }
    void setB(float B_) { B = B_; }
    void setPoint(float point_) { point = point_; }
    void setVie(int vie_) { vie = vie_; }
    float getPoint() { return point; }
    float getX();
    float getY();
    int getLife();
    void setImage(QImage imb);
private :
    float x;
    float y;
    float z;
    float size;
    int vie;
    float point;
    GLUquadric* quadrique;
    QImage im_b;
    GLuint texture;
    float infox;
    float infoy;
    float infow;
    float infoh;
    int id_;
    QString name_;
    float R =158;
    float V =253;
    float B =56;

};

#endif // BRICK_H
