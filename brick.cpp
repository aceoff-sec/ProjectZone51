#include "brick.h"

brick::brick(QString name, int id):Object()
{
    quadrique= gluNewQuadric();
    name_= name;
    id_ = id;
    //calcul des coordonnÃ©es + taille
    x=0;
    y=0;
    z=0;
    vie=1;
    infox=x-83;
    infoy=y+42;
    infow=13;
    infoh=6;


}

brick::~brick()
{
    // Destruction de la quadrique
    gluDeleteQuadric(quadrique);
}
void brick::LoseLife(){
    vie=0;
}
float brick::getInfo(QString value){
    if (value=='x'){return infox;}
    if (value=='y'){return infoy;}
    if (value=='w'){return infow;}
    if (value=='h'){return infoh;}
}
//int brick::getLife(){return vie;}
void brick::Display()
{

     glPushMatrix();


    //translate
    glTranslatef(x,y,z);
    // Affichage de la quadrique

    GLfloat colorAmbiante[]={1,0,1,1};

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE,colorAmbiante);

    if (vie==1){

    //Dessine un parallelipipaide
    glBegin(GL_QUADS);
        glColor3ub(158, 253, 56);
        glVertex3f(-70, 48, 0); glVertex3f( -83, 48, 0);
        glVertex3f( -83, 42, 0);
        glVertex3f(-70, 42, 0);

         glVertex3f(-70, 48, -1); glVertex3f(-83, 48, -1);
        glVertex3f( -83, 42, -1);
        glVertex3f( -70, 42, -1);

        glVertex3f(-70, 42, -1); glVertex3f(-70, 42, 0);
        glVertex3f( -83, 42, 0);
        glVertex3f( -83, 42, -1);

         glVertex3f(-70, 48, -1); glVertex3f( -83, 48, -1);
        glVertex3f( -83, 48, 0);
        glVertex3f(-70, 48, 0);

        glVertex3f( -83, 48, -1); glVertex3f( -83, 42, -1);
        glVertex3f( -83, 42, 0);
        glVertex3f( -83, 48, 0);

        glVertex3f(-70, 48, -1); glVertex3f(-70, 48, 0);
        glVertex3f(-70, 42, 0);
        glVertex3f(-70, 42, -1);
        glEnd();

    }

    glPopMatrix();


}


void brick::setX(float X){
    x=X;
    infox=x-83;

}
void brick::setY(float Y){
    y=Y;
    infoy=y+42;
}
float brick::getX(){
    return x;
}
float brick::getY(){return y;}

int brick::getLife(){return vie;}

QString brick::getName(){return name_;}

int brick::getId() {return id_;}
