#include "wall.h"

Wall::Wall():Object()
{   quadrique= gluNewQuadric();

    //calcul des coordonnÃ©es + taille
    xHorizontal=0;
    xVerticalGauche=-90;
    xVerticalDroite=180;
    yDown=-50;
    yUp=50;
    z=0;

}


Wall::~Wall()
{
    // Destruction de la quadrique
    gluDeleteQuadric(quadrique);
}


void Wall::Display()
{
    glPushMatrix();


    //Mur du bas
    glTranslatef(xHorizontal,yDown,z);

    //Dessine un rectangle
    glBegin(GL_POLYGON) ;
    glColor3f(1,0,0);
    glVertex2f(-90.0F,-0.5F) ;
    glColor3f(1,0,0);
    glVertex2f(-90.0F,0.5F) ;
    glColor3f(1,0,0);
    glVertex2f(90.0F,0.5F) ;
    glColor3f(1,0,0);
    glVertex2f(90.0F,-0.5F) ;
    glEnd();

    glPopMatrix();

    //Mur du haut
    glTranslatef(xHorizontal,yUp,z);

    glBegin(GL_POLYGON) ;
    glColor3f(0,1,0);
    glVertex2f(-90.0F,-0.5F) ;
    glColor3f(0,1,0);
    glVertex2f(-90.0F,0.5F) ;
    glColor3f(0,1,0);
    glVertex2f(90.0F,0.5F) ;
    glColor3f(0,1,0);
    glVertex2f(90.0F,-0.5F) ;
    glEnd();

    glPopMatrix();

    //Mur de gauche
    glTranslatef(xVerticalGauche,0,z);

    glBegin(GL_POLYGON) ;
    glColor3f(0,1,0);
    glVertex2f(-0.5F,-100.0F) ;
    glColor3f(0,1,0);
    glVertex2f(-0.5F,100.0F) ;
    glColor3f(0,1,0);
    glVertex2f(0.5F,100.0F) ;
    glColor3f(0,1,0);
    glVertex2f(0.5F,-100.0F) ;
    glEnd();

    glPopMatrix();

    //Mur de droite
    glTranslatef(xVerticalDroite,0,z);

    glBegin(GL_POLYGON) ;
    glColor3f(0,1,0);
    glVertex2f(-0.5F,-100.0F) ;
    glColor3f(0,1,0);
    glVertex2f(-0.5F,100.0F) ;
    glColor3f(0,1,0);
    glVertex2f(0.5F,100.0F) ;
    glColor3f(0,1,0);
    glVertex2f(0.5F,-100.0F) ;
    glEnd();

    glPopMatrix();
}
