#ifndef WALL_H
#define WALL_H

#include "object.h"
#include <GL/glu.h>

// Classe qui gère les murs du jeu (Nicolas)
class Wall : public Object
{
public:
    Wall(QString name, int id); // Constructuer avec nom et identifiant
    virtual ~Wall(); // Destructeur
    virtual void Display(); // Methode d'affichage
    virtual QString getName(); // Retourne le nom
    virtual int getId(); // Retourne l'identifiant
private:
    float xHorizontal; // Cordonnée
    float xVerticalGauche; // Cordonnée
    float xVerticalDroite; // Cordonnée
    float yDown; // Cordonnée
    float yUp; // Cordonnée
    float z; // Cordonnée
    float size; // taille
    GLUquadric* quadrique; // quadrique pour dessiner les murs
    int id_; // Retourne l'identifiant du mur
    QString name_; // Retourne le nom de l'objet
};

#endif // WALL_H
