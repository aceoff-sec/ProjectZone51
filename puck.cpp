#include "Puck.h"

Puck::Puck():Object()
{
    quadrique= gluNewQuadric();

    //calcul des coordonnÃ©es + taille
    x=10.;
    y=-15.;
    z=0.;
    size=4.;


}

Puck::~Puck()
{
    // Destruction de la quadrique
    gluDeleteQuadric(quadrique);
}


void Puck::Display()
{

     glPushMatrix();


    //translate
    glTranslatef(x,y,z);
    // Affichage de la quadrique

    GLfloat colorAmbiante[]={1.,0.,1.,1.};

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE,colorAmbiante);


    //Dessine un rectangle
    glBegin(GL_POLYGON) ;
      glVertex2f(-5.0F,-0.5F) ;
      glVertex2f(-5.0F,0.5F) ;
      glVertex2f(5.0F,0.5F) ;
      glVertex2f(5.0F,-0.5F) ;
      glEnd() ;


    glPopMatrix();






}
