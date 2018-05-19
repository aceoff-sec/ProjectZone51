#include <QGLWidget>
#include <GL/glu.h>
#include "object.h"
#include "string.h"
#include "qstring.h"
#ifndef Puck_H
#define Puck_H

// Classe qui gère le palet du casse-briques (Nicolas & Adrien)
class Puck : public Object // Hérite de la classe abstraite Object
{
public:
    Puck(QString name, int id); // Constructuer qui prend un nom et un identifiant
    virtual ~Puck(); // Destructeur
    virtual void Display(); // Methode d'affichage
    virtual float getInfo(QString value); // Retourne des caractéristiques selon la valeur
    virtual QString getName(); // Retourne le nom de l'objet
    virtual int getId(); // Retourne l'identifiant de l'objet
    void moveLeft(); // Bouger le palet à gauche
    void moveRight(); // Bouger le palet à droite
    void moveStop(); // Arrêter le déplacement du palet
    virtual float getSize() { return size; } // Retourne la taille du palet
    void setSize(float size_); // Actualise la taille du palet
protected:
    float x; // Coordonnée X
    float y; // Coordonnée Y
    float z; // Coordonnée Z
    float size; // Taille du palet
    GLUquadric* quadrique; // Objet quadrique pour dessiner le palet
    float infox; // information sur la coordonnée X
    float infoy; // information sur la coordonnée Y
    float infow; // information sur la largeur du palet
    float infoh; // information sur la hauteur du palet
    QString name_; // Nom de l'objet
    int id_; // Identifiant de l'objet
};

#endif // Puck_H

