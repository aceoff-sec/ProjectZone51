#include "Ball.h"

Ball::Ball(float Xb, float Yb, float Larg):Object()
{
    quadrique= gluNewQuadric();

    //calcul des coordonnÃ©es + taille
    x=Xb;
    y=Yb;
    z=0.;
    size=Larg;
    vie=1;
    dx=-1;
    dy=-1;
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

    if (vie==1){
    //Dessin sphere
    glColor3ub(187, 11, 11);
    gluSphere(quadrique,size,50,50);


    glPopMatrix();
    }


}

void Ball::setPos(/*x_, fly_,*/ int idx){
    switch(idx)
    {
        // Sortie de l'application
        case 0://palet
        {
        dy=-dy;
        x=x+dx*2;
        y=y+dy*2;
                    break;
        }
        case 1 ://mur gauche
        {
       dx=-dx;
       x=x+dx*2;
       y=y+dy*2;
            break;
        }
    case 2://brique
        {
        dy=-dy;
        x=x+dx*2;
        y=y+dy*2;
            break;

        }
     case 3 : //plafond
    {
    dx=-dx;
    x=x+dx*2;
    y=y+dy*2;
    break;}

        // Cas par defaut
        default:
        {
        x=x+dx*2;
        y=y+dy*2;
            return;
        }

}



}

float Ball::getX(){return x;}
float Ball::getY(){return y;}
float Ball::getR(){return size;}
