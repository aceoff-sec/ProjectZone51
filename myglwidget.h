#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include <QKeyEvent>
#include <QColor>
#include <QVector2D>
#include <Qtimer>
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
    void contact(Ball *boulet, Object *obj);


private:

    //Pour savoir si on doit afficher un triangle ou un carré
    bool triangle_ = false;
    //Variables pour définir les couleurs du fond
    float r=0.5;
    float v=0.5;
    float b=0.5;
    float alpha=0.5;
    int value;

    // Timer d'animation
    float m_TimeElapsed { 0.0f };
    QTimer m_AnimationTimer;
    //bool pushH_=true;
    std::vector<Object *> m_object;
    std::vector<Ball *> m_ball;
    Ball * ball1_;
    Ball * ball2_;
    Ball * ball3_;
    Puck * puck_;
    brick * brick_;
    Wall * wall1_;
    int idx;

    QImage image_;
    GLuint texture;
};

#endif // MYGLWIDGET_H
