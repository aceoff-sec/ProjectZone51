#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include <QKeyEvent>
#include <QColor>
#include <QVector2D>
#include "ball.h"
#include "puck.h"
#include "brick.h"
#include "wall.h"

// Classe dediee a l'affichage d'une scene OpenGL
class MyGLWidget : public QGLWidget
{
    Q_OBJECT

public:

    // Constructeur
    MyGLWidget(QWidget * parent = nullptr);

protected:

    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();
    //pression touche
    void keyPressEvent(QKeyEvent * event);

private:

    //Pour savoir si on doit afficher un triangle ou un carré
    bool triangle_ = false;
    //Variables pour définir les couleurs du fond
    float r=0.5;
    float v=0.5;
    float b=0.5;
    float alpha=0.5;
    //Variable pour définir couleur de la primitive
    /*int primitiveR_=0;
    int primitiveV_=0;
    int primitiveB_=255;
    //Variable pour masquer ou pas la primitive
    bool pushH_=true;*/
    std::vector<Object *> m_object;
    Ball * ball1_;
    Puck * puck_;
    brick * brick_;
    Wall * wall1_;
};

#endif // MYGLWIDGET_H
