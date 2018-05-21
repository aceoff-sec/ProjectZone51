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

// Classe dediee a l'affichage d'une scene OpenGL (Adrien & Nicolas)
class MyGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    MyGLWidget(QWidget * parent = nullptr); // Constructeur par défaut
    void static moveLeft(); // Méthode qui appelle la fonction moveLeft du palet
    void static moveRight(); // Méthode qui appelle la fonction moveRight du palet
    void static moveStop(); // Méthode qui appelle la fonction moveStop du palet
    bool static getSpace() { return space; } // Retourne si la barre d'espace a été activée ou pas
    void static setSize(float size); // Méthode qui appelle la fonction setSize du palet
    void static setName(QString name) { name_ = name; } // Enregistre le nom du joueur
    static QString name_; // Nom du joueur
protected:
    void initializeGL(); // Fonction d'initialisation
    void resizeGL(int width, int height); // Fonction de redimensionnement
    void paintGL(); // Fonction d'affichage
    void keyPressEvent(QKeyEvent * event);  // Pour utiliser les flèches du clavier
    void contact(Ball *boulet, Object *obj); // Pour intéragir selon le contact des objets (rebonds)
    void displayInfo(); // Pour afficher les infos du jeu
    void Again(); // Pour recommencer une partie que l'on gagne ou que l'on perde
    bool Nottouched(Object *obj,std::vector<int> vect); // Pour savoir si une brique a été touchée ou non
    void createBrick(); // Pour recréer un affichage entier de brique selon le niveau
    void save(QString player, float val); // Pour enregistrer le nom du joueur et le score
private:
    float r=0.5; // Composante rouge
    float v=0.5; // Composante verte
    float b=0.5; // Composante bleue
    float alpha=0.5; // Canal alpha
    int value;
    float m_TimeElapsed { 0.0f }; // variable utile pour le timer
    QTimer m_AnimationTimer; // Timer d'animation
    std::vector<Object *> m_object; // Vecteur d'objets
    std::vector<Ball *> m_ball; // Vecteur de balles
    std::vector<int> touched; // Vecteur des briques touchées
    Ball * ball1_; // Balle 1
    Ball * ball2_; // Balle 2
    Ball * ball3_; // Balle 3
    Ball * ball4_; // Balle 4 (car quand on recommence une partie, une balle est détruite directement, de ce fait on reste à 3 disponibles)
    static Puck * puck_; // Palet
    brick * brick_; // Brique
    Wall * walls_; // Mur
    int idx; // Identifiant
    bool firstBall = true; // si c'est la première balle
    bool secondBall = false; // si c'est la deuxième balle
    bool thirdBall = false; // si c'est la troisième balle
    int nbBrick; // Nombre de briques
    int nbBalls = 3; // Nombre de balles
    QImage image_; // Image pour texture
    QImage image_b; // Image pour texture
    GLuint texture; // Pour la texture
    QPainter painter; // Pour dessiner
    int score; // Pour le score du joueur
    int level; // Pour identifier le niveau en cours
    QString time_; // Pour afficher le temps en cours
    QString score_; // Pour affichier le score en cours
    QString level_; // Pour afficher le niveau en cours
    QString nbBalls_; // Pour afficher le nombre de balles disponibles
    static bool space; // Si la barre d'espace a été activée
    bool firstspace = true; // Si c'est la première fois qu'on appuie sur la barre d'espace
    bool firstTime = true; // Si c'est la première fois que l'on commence le niveau
    int vict=0;//Indique la victoire 2 ou la défaite 1 ou la partie continue 0
};

#endif // MYGLWIDGET_H
