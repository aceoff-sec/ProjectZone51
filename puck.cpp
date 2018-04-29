#include "Puck.h"

Puck::Puck(QString name, int id):Object()
{
    quadrique= gluNewQuadric();

    //calcul des coordonnÃ©es + taille
    x=-19;
    y=-45.;
    z=0.;
    size=4.;
    infox=x;
    infoy=y;
    infow=10.5;
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


    //translate
    glTranslatef(x,y,z);
    // Affichage de la quadrique

    GLfloat colorAmbiante[]={1.,0.,1.,1.};

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE,colorAmbiante);


    //Dessine un parallelipipaide
    glBegin(GL_QUADS);
    glColor3ub(249,66,158);
    glVertex3f(30., 1., 0.); glVertex3f( -1., 1., 0.);
    glVertex3f( -1., -1., 0.);
    glVertex3f(30., -1., 0.);

     glVertex3f(30., 1., -1.); glVertex3f(1., -1., -1.);
    glVertex3f( -1., -1., -1.);
    glVertex3f( -1., 1., -1.);

    glVertex3f(30., -1., -1.); glVertex3f(30., -1., 0.);
    glVertex3f( -1., -1., 0.);
    glVertex3f( -1., -1., -1.);

     glVertex3f(30., 1., -1.); glVertex3f( -1., 1., -1.);
    glVertex3f( -1., 1., 0.);
    glVertex3f(30., 1., 0.);

    glVertex3f( -1., 1., -1.); glVertex3f( -1., -1., -1.);
    glVertex3f( -1., -1., 0.);
    glVertex3f( -1., 1., 0.);

    glVertex3f(30., 1., -1.); glVertex3f(30., 1., 0.);
    glVertex3f(30., -1., 0.);
    glVertex3f(30., -1., -1);
    glEnd();



    glPopMatrix();


}


void Puck::moveLeft() {
    if(x>=-83) {
        x=x-5;
        infox=x;
    }
    else {

    }
}

void Puck::moveRight() {
    if(x<=53) {
        x=x+5;
        infox=x;
    }
    else {

    }
}

QString Puck::getName(){return name_;}

int Puck::getId() {return id_;}

