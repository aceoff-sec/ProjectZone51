#include "wall.h"

Wall::Wall(QString name, int id):Object()
{   quadrique= gluNewQuadric();
    //calcul des coordonnÃ©es + taille
    xHorizontal=0;
    xVerticalGauche=-90;
    xVerticalDroite=180;
    yDown=-50;
    yUp=50;
    z=0;
    name_ = name;
    id_ = id;
}

Wall::~Wall()
{
    // Destruction de la quadrique
    gluDeleteQuadric(quadrique);
}

void Wall::Display()
{
    glPushMatrix();
    //couleurs des murs
    GLfloat colorAmbianteB[]={1.,0.,0.,1.};
    GLfloat colorAmbianteH[]={0.,1.,0.,1.};
    GLfloat Noir[]={0.,0.,0.,1.};
    //Mur du bas
    glTranslatef(xHorizontal,yDown,z);

    //Dessine un rectangle
    glBegin(GL_POLYGON) ;
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE,colorAmbianteB);
    //glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,Noir);
    glVertex2f(-90.0F,-0.5F) ;
    glVertex2f(-90.0F,0.5F) ;
    glVertex2f(90.0F,0.5F) ;
    glVertex2f(90.0F,-0.5F) ;
    glEnd();

    glPopMatrix();
    //Mur du haut
    glTranslatef(xHorizontal,yUp,z);

    glBegin(GL_POLYGON) ;
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE,colorAmbianteH);

    //glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,Noir);

    glVertex2f(-90.0F,-0.5F) ;
    glVertex2f(-90.0F,0.5F) ;
    glVertex2f(90.0F,0.5F) ;
    glVertex2f(90.0F,-0.5F) ;
    glEnd();

    glPopMatrix();
    //Mur de gauche
    glTranslatef(xVerticalGauche,0,z);

    glBegin(GL_POLYGON) ;
    glVertex2f(-0.5F,-100.0F) ;
    glVertex2f(-0.5F,100.0F) ;
    glVertex2f(0.5F,100.0F) ;
    glVertex2f(0.5F,-100.0F) ;
    glEnd();

    glPopMatrix();
    //Mur de droite
    glTranslatef(xVerticalDroite,0,z);

    glBegin(GL_POLYGON) ;
    glVertex2f(-0.5F,-100.0F) ;
    glVertex2f(-0.5F,100.0F) ;
    glVertex2f(0.5F,100.0F) ;
    glVertex2f(0.5F,-100.0F) ;
    glEnd();

    glPopMatrix();
}

QString Wall::getName(){return name_;}

int Wall::getId() {return id_;}
