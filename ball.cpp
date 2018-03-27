#include "Ball.h"

Ball::Ball():Object()
{
    quadrique= gluNewQuadric();

    //calcul des coordonnÃ©es + taille
    x=0.;
    y=-15.;
    z=0.;
    size=3.5;


}

Ball::~Ball()
{
    // Destruction de la quadrique
    gluDeleteQuadric(quadrique);
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
