#include "Puck.h"
#include <QDebug>

Puck::Puck(QString name, int id):Object()
{
    quadrique= gluNewQuadric();

    //calcul des coordonnÃ©es + taille
    x=-19;
    y=-45.;
    z=0.;
    size=0;
    infox=x;
    infoy=y;
    infow=10.5+(size/2);
    infoh=2.;
    name_ = name;
    id_ = id;

}

Puck::~Puck()
{
    // Destruction de la quadrique
    gluDeleteQuadric(quadrique);
}

float Puck::getInfo(QString value){
    if (value=="posx"){return infox;};
    if (value=="posy"){return infoy;};
    if (value=="posw"){return infow;};
    if (value=="posh"){return infoh;};
}
void Puck::Display()
{

     glPushMatrix();
    glDisable(GL_COLOR_MATERIAL);

    //translate
    glTranslatef(x,y,z);
    // Affichage de la quadrique

    GLfloat colorAmbiante[]={249/255.,66/255.,158/255.,1.};

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE,colorAmbiante);
    GLfloat Noir[]={0.,0.,0.,1.};
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,Noir);

    //Dessine un parallelipipaide
    glBegin(GL_QUADS);
    //glColor3ub(249,66,158);
    glVertex3f(30+(size/2), 1., 0.); glVertex3f( -1-(size/2), 1., 0.);
    glVertex3f( -1-(size/2), -1., 0.);
    glVertex3f(30+(size/2), -1., 0.);

     glVertex3f(30+(size/2), 1., -1.); glVertex3f(-1-(size/2), 1., -1.);
    glVertex3f( -1., -1., -1.);
    glVertex3f( 30+(size/2), -1., -1.);

    glVertex3f(30+(size/2), -1., -1.); glVertex3f(30+(size/2), -1., 0.);
    glVertex3f( -1-(size/2), -1., 0.);
    glVertex3f( -1-(size/2), -1., -1.);

     glVertex3f(30+(size/2), 1., -1.); glVertex3f( -1-(size/2), 1., -1.);
    glVertex3f( -1-(size/2), 1., 0.);
    glVertex3f(30+(size/2), 1., 0.);

    glVertex3f( -1-(size/2), 1., -1.); glVertex3f( -1-(size/2), -1., -1.);
    glVertex3f( -1-(size/2), -1., 0.);
    glVertex3f( -1-(size/2), 1., 0.);

    glVertex3f(30+(size/2), 1., -1.); glVertex3f(30+(size/2), 1., 0.);
    glVertex3f(30+(size/2), -1., 0.);
    glVertex3f(30+(size/2), -1., -1);
    glEnd();



    glPopMatrix();


}


void Puck::moveLeft() {
    if(x>=-83+(size/2)) {
        x=x-6;
        infox=x;
    }
    else {

    }
}

void Puck::moveRight() {
    if(x<=53-(size/2)) {
        x=x+6;
        infox=x;
    }
    else {

    }
}

void Puck::moveStop() {
    x=x;
    infox=x;
}

QString Puck::getName(){return name_;}

int Puck::getId() {return id_;}

void Puck::setSize(float size_) {
    size = size_;
    infow=10.5+(size/2);
}
