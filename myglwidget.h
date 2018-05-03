#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include <QMessageBox>
#include <QKeyEvent>
#include <GL/glu.h>
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
    void static moveLeft();
    void static moveRight();
    bool static getSpace() { return space; }

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
    void displayInfo();
    void Again();
    bool Nottouched(Object *obj,std::vector<int> vect);
    void createBrick();

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
    std::vector<int> touched;
    Ball * ball1_;
    Ball * ball2_;
    Ball * ball3_;
    Ball * ball4_;
    static Puck * puck_;
    brick * brick_;
    Wall * walls_;
    int idx;
    bool firstBall = true;
    bool secondBall = false;
    bool thirdBall = false;
    int nbBrick;
    int nbBalls = 3;

    QImage image_;
    QImage image_b;
    GLuint texture;
    QPainter painter;
    int score;
    int level;
    QString time_;
    QString score_;
    QString level_;
    QString nbBalls_;
    static bool space;
    bool firstspace = true;
    bool firstTime = true;
};

#endif // MYGLWIDGET_H
