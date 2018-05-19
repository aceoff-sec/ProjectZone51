#include <QGLWidget>
#include <GL/glu.h>
#include "object.h"
#include "qstring.h"

#ifndef BRICK_H
#define BRICK_H

// Classe qui permet de gérer les briques et leur affchage, ainsi que le nombre de points par briques en fonction des vie des briques (Adrien)
class brick: public Object // Hérite de classe abstraite Object
{
public:
    brick(QString name, int id, QImage imb);  //Constructeur qui prendre en paramètre un nom pour identifier l'objet, un identifiant et une image
    virtual ~brick();  // Destructeur
    virtual void Display(); // Méthode d'affichage
    virtual void LoseLife(); // Méthodes relatives à la vie (perd une vie)
    int getLife(); // Méthode qui retourne la vie d'une brique
    virtual float getInfo(QString value); // Méthode qui retourne differents paramètre selon la valeur
    virtual QString getName(); // Méthode qui retourne le nom de l'objet
    virtual int getId(); // Méthode qui retourne l'identifiant de la brique
    void setX(float X); // Méthode qui actualise une variable
    void setY(float Y); // Méthode qui actualise une variable
    void setR(float R_) { R = R_; } // Méthode qui actualise une variable
    void setV(float V_) { V = V_; } // Méthode qui actualise une variable
    void setB(float B_) { B = B_; } // Méthode qui actualise une variable
    void setPoint(float point_) { point = point_; } // Méthode qui actualise une variable
    void setVie(int vie_) { vie = vie_; } // Méthode qui actualise une variable
    float getPoint() { return point; } // Méthode retourne l'état d'une variable
    float getX(); // Méthode retourne l'état d'une variable
    float getY(); // Méthode retourne l'état d'une variable
    void setImage(QImage imb); // Méthode retourne l'état d'une variable
private :
    float x; // Coordonnée X
    float y; // Coordonnée Y
    float z; // Coordonnée Z
    float size; // Largeur de la brique
    int vie; // Vie de la brique
    float point; // Point que rapporte la brique quand elle est détruite
    GLUquadric* quadrique; // Quadrique pour dessiner une brique
    QImage im_b; // Pour image brique
    GLuint texture; // Pour texture brique
    float infox; // Informations sur la position X de la brique
    float infoy; // Informations sur la position Y de la brique
    float infow; // Informations sur la largeur de la brique
    float infoh; // Informations sur la hauteur de la brique
    int id_; // Identifiant de la brique
    QString name_; // Nom de l'objet brique
    float R =158; // Composante rouge
    float V =253; // Composante verte
    float B =56; // Composante bleue

};

#endif // BRICK_H
