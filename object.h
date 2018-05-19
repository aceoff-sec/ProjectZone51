#include "qstring.h"
#ifndef OBJECT_H
#define OBJECT_H

// Classe abstraite qui gère les méthodes et l'affichage en commun des différents objets (Adrien & Nicolas)
class Object
{
public:
    Object(QString name, int id); // Constructeur qui prend un nom et un identifiant en paramètre
    Object(); // Constructeur par défaut si rien n'est précisé
    virtual ~Object(); // Destructeur
    virtual void Display(); // Gère l'affichage des objets
    virtual void LoseLife(); // Gère la vie des objets
    virtual float getInfo(QString value); // Retourne des caractéristiques selons les objets
    virtual int getLife(); // Retourne la vie d'un objet
    virtual float getPoint(); // Retour le nombre de point d'un objet
    virtual QString getName(); // Retourne le nom d'un objet
    virtual int getId(); // Retourne l'identifiant d'un objet
    virtual float getSize(); // Retourne la largeur d'un objet
};

#endif // OBJECT_H
