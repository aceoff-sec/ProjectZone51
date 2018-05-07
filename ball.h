#include <GL/glu.h>
#include <QColor>
#include "object.h"
#include <QGLWidget>

#ifndef BALL_H
#define BALL_H

// Classe qui permet de gérer les balles du jeu ainsi que leurs mouvements
class Ball : public Object // Hérite de la classe abstraire Object
{
public:
    // Constructeur
    Ball(float Xb,float Yb,float Larg, int id);

    // Destructeur
    virtual ~Ball();

    // Methode d'affichage
    virtual void Display();

    // Méthodes relatives à la vie
    virtual void LoseLife();
    virtual int getLife();

    // Modification position
    void setPos();
    float getX();
    float getY();
    float getR();
    float getdx();
    float getdy();
    void setdx(float x_);
    void setdy(float y_);
    void setx(float x_) { x = x_; }
    void sety(float y_) { y = y_; }

    // Retourne le numéro de la balle en cours
    virtual int getId() {return id_;}

private:
    float x;
    float y;
    float z;
    float size;
    int vie;
    float dx;
    float dy;
    GLUquadric* quadrique;
    int id_;
    int val_;
};

#endif // Ball_H



