#include "Ball.h"

Ball::Ball(float Xb, float Yb, float Larg, int id):Object()
{
    // On crée une nouvelle quadrique
    quadrique= gluNewQuadric();

    // Mise à jour des chanmps de la classe pour une balle
    x=Xb;
    y=Yb;
    z=0.;
    size=Larg;
    id_=id;

    // On donne la possibilité à la balle d'avoir 3 directions possibles de départ (choisit aléatoirement)
    val_ = rand()%3 +1;
    if(val_ == 1) { dx=-0.04; dy=-0.04; }
    if(val_ == 2) { dx=0.04; dy=-0.04; }
    if(val_ == 3) { dx=0; dy=-0.04; }

}

Ball::~Ball()
{
    // Destruction de la quadrique
    gluDeleteQuadric(quadrique);
}



void Ball::Display()
{

    glPushMatrix();
     glDisable(GL_COLOR_MATERIAL);
    // Translate
    glTranslatef(x,y,z);

    // Eclairage de la quadrique (utile si une lampe est mise en place uniquement)
    GLfloat colorAmbiante[]={1.,0.,0.,1.};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE,colorAmbiante);
    GLfloat Noir[]={0.,0.,0.,1.};
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,Noir);
    // Dessin de la quadrique (3D)

    gluSphere(quadrique,size,50,50);

    glPopMatrix();

}

void Ball::setPos(){
    x=x+dx;
    y=y+dy;
}

float Ball::getX(){return x;}
float Ball::getY(){return y;}
float Ball::getR(){return size;}
float Ball::getdx(){return dx;}
float Ball::getdy(){return dy;}
void Ball::setdx(float x_){dx=x_;}
void Ball::setdy(float y_){dy=y_;}
