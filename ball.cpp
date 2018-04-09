#include "Ball.h"

Ball::Ball(float Xb, float Yb, float Larg, int id):Object()
{
    quadrique= gluNewQuadric();

    //calcul des coordonnÃ©es + taille
    x=Xb;
    y=Yb;
    z=0.;
    size=Larg;
    vie=1;
    dx=-0.01;
    dy=-0.01;
    id_=id;
}

Ball::~Ball()
{
    // Destruction de la quadrique
    gluDeleteQuadric(quadrique);
}


void Ball::LoseLife(){
    vie=0;
}
void Ball::Display()
{

    glPushMatrix();


    //translate
    glTranslatef(x,y,z);
    // Affichage de la quadrique

    GLfloat colorAmbiante[]={1.,0.,1.,1.};

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE,colorAmbiante);


    //Dessin sphere
    glColor3ub(187, 11, 11);
    gluSphere(quadrique,size,50,50);


    glPopMatrix();

}

void Ball::setPos(){
    x=x+2.5*dx;
    y=y+2.5*dy;
}

//int Ball::getLife(){return vie;}



float Ball::getX(){return x;}
float Ball::getY(){return y;}
float Ball::getR(){return size;}
float Ball::getdx(){return dx;}
float Ball::getdy(){return dy;}
void Ball::setdx(float x_){dx=x_;}
void Ball::setdy(float y_){dy=y_;}
int Ball::getLife(){return vie;}
