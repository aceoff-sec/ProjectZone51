#include "myglwidget.h"
#include <QApplication>
#include <QDesktopWidget>

// Declarations des constantes
const unsigned int WIN_WIDTH  = 1600;
const unsigned int WIN_HEIGHT = 900;
const float ASPECT_RATIO      = static_cast<float>(WIN_WIDTH) / WIN_HEIGHT;
const float ORTHO_DIM         = 50.0f;


// Constructeur
MyGLWidget::MyGLWidget(QWidget * parent) : QGLWidget(parent)
{
    // Reglage de la taille/position
    setFixedSize(WIN_WIDTH, WIN_HEIGHT);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());
}


// Fonction d'initialisation
void MyGLWidget::initializeGL()
{
    // Reglage de la couleur de fond
    glClearColor(r,v,b,alpha);
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
    // Reinitialisation du tampon de couleur et couleur de fond par défaut
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    // Reglage de la couleur
    glClearColor(r,v,b,alpha);
    glColor3ub(primitiveR_,primitiveV_,primitiveB_);

    //Ensemble des vertices
    glEnableClientState(GL_VERTEX_ARRAY);
    GLfloat vertices[] = { 0, 10, -5, 0, 5, 0, // triangle
                         -15, 15, 15, 15, 15, -10, -15, -10};  // rectangle
    glVertexPointer(2, GL_FLOAT, 0, vertices);

    if(pushH_) { //Si on ne masque pas la primitive
        if(!triangle_) //Si la forme n'est pas un triangle, on le dessine
        {
            glDrawArrays(GL_TRIANGLES, 0, 3);
        }
        else { //Sinon on dessine un rectangle
            glDrawArrays(GL_QUADS, 3, 4);
        }
    }
    else { //Sinon on masque la primitive, donc juste besoin d'afficher le fond sans dessiner dessus
        glClearColor(r,v,b,alpha);
    }

}


// Fonction de gestion d'interactions clavier
void MyGLWidget::keyPressEvent(QKeyEvent * event)
{
    switch(event->key())
    {
        // Changement de couleur du fond
        case Qt::Key_B:
        {
            r = (float)rand() / (float)RAND_MAX; //Pour avoir un flottant entre 0 et 1
            v = (float)rand() / (float)RAND_MAX;
            b = (float)rand() / (float)RAND_MAX;
            alpha = (float)rand() / (float)RAND_MAX;
            break;
        }

        // Changement de couleur de l'objet
        case Qt::Key_C:
        {
            primitiveR_ = (rand() % (255 - 0 + 1)) + 0; // Pour avoir un nombre aléatoire entre 0 et 255 : (rand() % (MAX - MIN + 1)) + MIN;
            primitiveV_ = (rand() % (255 - 0 + 1)) + 0;
            primitiveB_ = (rand() % (255 - 0 + 1)) + 0;
            break;
        }

        // Affichage/Masquage de l'objet
        case Qt::Key_H:
        {
            pushH_=!pushH_;
            break;
        }

        // Changement de l'objet a afficher
        case Qt::Key_Space:
        {
            triangle_=!triangle_;
            break;
        }

        // Sortie de l'application
        case Qt::Key_Escape:
        {
            window()->close(); //On ferme la fenêtre
            break;
        }

        //Déplacement vers la droite
        case Qt::Key_Right:
        {
            glTranslatef(1,0,0);
            break;
        }

        //Déplacement vers la gauche
        case Qt::Key_Left:
        {
            glTranslatef(-1,0,0);
            break;
        }

        //Déplacement vers le haut
        case Qt::Key_Up:
        {
            glTranslatef(0,1,0);
            break;
        }

        //Déplacement vers le bas
        case Qt::Key_Down:
        {
            glTranslatef(0,-1,0);
            break;
        }

        //Rotation
        case Qt::Key_R:
        {
            glRotatef(20,0,0,1);
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

