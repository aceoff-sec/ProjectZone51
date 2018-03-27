#include "Puck.h"

Puck::Puck():Object()
{
    quadrique= gluNewQuadric();

    //calcul des coordonnÃ©es + taille
    x=0;
    y=-40.;
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


    //Dessine un parallelipipaide
    glBegin(GL_QUADS);
        glColor3ub(249,66,158);
        glVertex3f(50.+x, 2., 0.); glVertex3f( -2.+x, 2., 0.);
        glVertex3f( -2.+x, -2., 0.);
        glVertex3f(50.+x, -2., 0.);

         glVertex3f(50.+x, 2., -1.); glVertex3f(2.+x, -2., -1.);
        glVertex3f( -2.+x, -2., -1.);
        glVertex3f( -2.+x, 2., -1.);

        glVertex3f(50.+x, -2., -1.); glVertex3f(50.+x, -2., 0.);
        glVertex3f( -2.+x, -2., 0.);
        glVertex3f( -2.+x, -2., -1.);

         glVertex3f(50.+x, 2., -1.); glVertex3f( -2.+x, 2., -1.);
        glVertex3f( -2.+x, 2., 0.);
        glVertex3f(50.+x, 2., 0.);

        glVertex3f( -2.+x, 2., -1.); glVertex3f( -2.+x, -2., -1.);
        glVertex3f( -2.+x, -2., 0.);
        glVertex3f( -2.+x, 2., 0.);

        glVertex3f(50.+x, 2., -1.); glVertex3f(50.+x, 2., 0.);
        glVertex3f(50.+x, -2., 0.);
        glVertex3f(50.+x, -2., -1);
        glEnd();



    glPopMatrix();


}


void Puck::setX(float X){
    x=X;
}
float Puck::getX(){
    return x;
}
float Puck::getY(){return y;}
