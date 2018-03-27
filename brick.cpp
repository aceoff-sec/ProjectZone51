#include "brick.h"

brick::brick():Object()
{
    quadrique= gluNewQuadric();

    //calcul des coordonnÃ©es + taille
    x=0.;
    y=0.;
    z=0.;
    vie=1;


}

brick::~brick()
{
    // Destruction de la quadrique
    gluDeleteQuadric(quadrique);
}


void brick::Display()
{

     glPushMatrix();


    //translate
    glTranslatef(x,y,z);
    // Affichage de la quadrique

    GLfloat colorAmbiante[]={1.,0.,1.,1.};

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE,colorAmbiante);

    if (vie==1){

    //Dessine un parallelipipaide
    glBegin(GL_QUADS);
        glColor3ub(158, 253, 56);
        glVertex3f(17.-80., 3.+45., 0.); glVertex3f( -3.-80., 3.+45., 0.);
        glVertex3f( -3.-80., -3.+45., 0.);
        glVertex3f(17.-80., -3.+45., 0.);

         glVertex3f(17.-80., 3.+45., -1.); glVertex3f(3.-80., -3.+45., -1.);
        glVertex3f( -3.-80., -3.+45., -1.);
        glVertex3f( -3.-80., 3.+45., -1.);

        glVertex3f(17.-80., -3.+45., -1.); glVertex3f(17.-80., -3.+45., 0.);
        glVertex3f( -3.-80., -3.+45., 0.);
        glVertex3f( -3.-80., -3.+45., -1.);

         glVertex3f(17.-80., 3.+45., -1.); glVertex3f( -3.-80., 3.+45., -1.);
        glVertex3f( -3.-80., 3.+45., 0.);
        glVertex3f(17.-80., 3.+45., 0.);

        glVertex3f( -3.-80., 3.+45., -1.); glVertex3f( -3.-80., -3.+45., -1.);
        glVertex3f( -3.-80., -3.+45., 0.);
        glVertex3f( -3.-80., 3.+45., 0.);

        glVertex3f(17.-80., 3.+45., -1.); glVertex3f(17.-80., 3.+45., 0.);
        glVertex3f(17.-80., -3.+45., 0.);
        glVertex3f(17.-80., -3.+45., -1);
        glEnd();

    }

    glPopMatrix();


}


void brick::setX(float X){
    x=X;
}
void brick::setY(float Y){
    y=Y;
}
float brick::getX(){
    return x;
}
float brick::getY(){return y;}

int brick::viechy(){return vie;}
