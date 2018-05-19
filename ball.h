#include <GL/glu.h>
#include <QColor>
#include "object.h"
#include <QGLWidget>

#ifndef BALL_H
#define BALL_H

// Classe qui permet de gérer les balles du jeu ainsi que leurs mouvements (Adrien)
class Ball : public Object // Hérite de la classe abstraire Object
{
public:
    Ball(float Xb,float Yb,float Larg, int id); // Constructeur avec une position de départ, un rayon et un identifiant
    virtual ~Ball(); // Destructeur
    virtual void Display(); // Méthode d'affichage pour la balle qui va donc aussi gérer l'animation du mouvement
    void setPos(); // Méthode qui actualise la position de la balle
    float getX(); // Méthode qui renvoie la position X de la balle
    float getY(); // Méthode qui renvoie la position Y de la balle
    float getR(); // Méthode qui renvoie le rayon R de la balle
    float getdx(); // Méthode qui renvoie la position dX de la balle
    float getdy(); // Méthode qui renvoie la position dY de la balle
    void setdx(float x_); // Méthode qui actualise la variable dX
    void setdy(float y_); // Méthode qui actualise la variable dY
    void setx(float x_) { x = x_; } // Méthode qui actualise la variable X
    void sety(float y_) { y = y_; } // Méthode qui actualise la variable Y
    virtual int getId() {return id_;} // Retourne le numéro de la balle en cours
private:
    float x; // Coordonnée X
    float y; // Coordonnée Y
    float z; // Coordonnée Z
    float size; // Largeur de la balle
    float dx; // Coordonnées dX
    float dy; // Coordonnées dY
    GLUquadric* quadrique; // Objet quadrique pour dessiner la balle
    int id_; // Identifiant de la balle
    int val_;
};

#endif // Ball_H



