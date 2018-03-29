#include "myglwidget.h"
#include <QApplication>
#include <QDesktopWidget>


// Declarations des constantes
const unsigned int WIN_WIDTH  = 900;
const unsigned int WIN_HEIGHT = 500;
const float ASPECT_RATIO      = static_cast<float>(WIN_WIDTH) / WIN_HEIGHT;
const float ORTHO_DIM         = 50.0f;


// Constructeur
MyGLWidget::MyGLWidget(QWidget * parent) : QGLWidget(parent)
{
    // Connexion du timer
    connect(&m_AnimationTimer,  &QTimer::timeout, [&] {
        m_TimeElapsed += 1.0f / 12.0f;
        updateGL();
    });

    m_AnimationTimer.setInterval(50);
    m_AnimationTimer.start();
    // Reglage de la taille/position

    move(QApplication::desktop()->screen()->rect().center() - rect().center());
}


// Fonction d'initialisation
void MyGLWidget::initializeGL()
{
    // Reglage de la couleur de fond
    glClearColor(r,v,b,alpha);

    // Activation du zbuffer
    glEnable(GL_DEPTH_TEST);
    //ajout
    ball1_ = new Ball(0.,-0.75,1.5);
    ball2_ = new Ball(3.5,-0.75,1.5);
    ball3_ = new Ball(-3.5,-0.75,1.5);
    puck_ = new Puck();
    wall1_ = new Wall();
    m_ball.push_back(ball1_);
    m_ball.push_back(ball2_);
    m_ball.push_back(ball3_);
    m_object.push_back(puck_);


    for (int i=0;i<7;i++){
        for(int j=0;j<5;j++){
        brick_= new brick();
        brick_->setY(-j*10.);
            brick_->setX(i*25.);

           m_object.push_back(brick_);
        }
    }

    m_object.push_back(wall1_);

    image_ = QGLWidget::convertToGLFormat(QImage(":/fond.jpg"));

    // Create an openGL texture
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_.width(), image_.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, static_cast<GLubyte*>(image_.bits()));



}


// Fonction de redimensionnement
void MyGLWidget::resizeGL(int width, int height)
{
    // Definition du viewport (zone d'affichage)
    glViewport(0,0,width,height);

    // Definition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ORTHO_DIM * ASPECT_RATIO, ORTHO_DIM * ASPECT_RATIO, -ORTHO_DIM, ORTHO_DIM, -2.0f * ORTHO_DIM, 2.0f * ORTHO_DIM);

    // Definition de la matrice de modele
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


// Fonction d'affichage
void MyGLWidget::paintGL()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Reinitialisation des tampons
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    /*glEnable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
    glBindTexture(GL_TEXTURE_2D, texture);

    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex2f( -100.0f, -50.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex2f( -100.0f, 50.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex2f( 100.0f, 50.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex2f( 100.0f, -50.0f);
    glEnd();

    glEnable(GL_DEPTH_TEST); */

    for(Ball * boul : m_ball) {
        idx=contact(boul);
        boul->setPos(idx);
        boul->Display();

    }
    for(Object * obj : m_object) {
        obj->Display();

    }

}

// Fonction de gestion d'interactions clavier
void MyGLWidget::keyPressEvent(QKeyEvent * event)
{
    switch(event->key())
    {
        // Sortie de l'application
        case Qt::Key_Escape:
        {
            exit(0);
        }

        // Mouvement du palet à gauche
        case Qt::Key_Left:
        {
            puck_->moveLeft();
            break;
        }

        // Mouvement du palet à droite
        case Qt::Key_Right:
        {
            puck_->moveRight();
            break;
        }

        // Cas par defaut
        default:
        {
            // Ignorer l'evenement
            event->ignore();
            return;
        }
    }

    // Acceptation de l'evenement et mise a jour de la scene
    event->accept();
    updateGL();
}


int MyGLWidget::contact(Ball *boulet)
{   value=32;
    if (boulet->getX()+boulet->getR() > ORTHO_DIM*ASPECT_RATIO){
        value=3;//droit
    }
    if (boulet->getX()-boulet->getR() < -ORTHO_DIM*ASPECT_RATIO){
        value=1;//gauche
    }
    if (boulet->getY()-boulet->getR() < -ORTHO_DIM){
        value=0;//bas

    }
    if (boulet->getY()+boulet->getR() > ORTHO_DIM){
        value=2;//haut

    }
return value;
}
