#include "myglwidget.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>

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

    m_AnimationTimer.setInterval(20);
    m_AnimationTimer.start();
    // Reglage de la taille/position

    move(QApplication::desktop()->screen()->rect().center() - rect().center());
}


// Fonction d"initialisation
void MyGLWidget::initializeGL()
{
    // Reglage de la couleur de fond
    //glClearColor(r,v,b,alpha);

    // Activation du zbuffer
    glEnable(GL_DEPTH_TEST);
    //ajout
    ball1_ = new Ball(0.,-0.75,1.5,1);
    ball2_ = new Ball(3.5,-0.75,1.5,2);
    ball3_ = new Ball(-3.5,-0.75,1.5,3);
    puck_ = new Puck("Puck",1);
    walls_ = new Wall("Wall",1);
    m_ball.push_back(ball1_);
    m_ball.push_back(ball2_);
    m_ball.push_back(ball3_);
    m_object.push_back(puck_);


    for (int i=0;i<10;i++){
        for(int j=0;j<5;j++){
        brick_= new brick("Brick",i+j);
        brick_->setY(-j*10.);
            brick_->setX(i*17);

           m_object.push_back(brick_);
        }
    }

    m_object.push_back(walls_);

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
    // Definition du viewport (zone d"affichage)
    glViewport(0,0,width,height);

    // Definition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ORTHO_DIM * ASPECT_RATIO, ORTHO_DIM * ASPECT_RATIO, -ORTHO_DIM, ORTHO_DIM, -2.0f * ORTHO_DIM, 2.0f * ORTHO_DIM);

    // Definition de la matrice de modele
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


// Fonction d"affichage
void MyGLWidget::paintGL()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Reinitialisation des tampons
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    glEnable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
    glColor3f(1.0f,1.0f,1.0f);


    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex2f( -100.0f, -50.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex2f( -100.0f, 50.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex2f( 100.0f, 50.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex2f( 100.0f, -50.0f);
    glEnd();

    glDisable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);



    if(firstBall == true && secondBall == false && thirdBall == false) {
        m_ball[0]->Display();
        int i=0;
        for(Object * obj : m_object) {
            contact(m_ball[0],obj);
            if (obj->getLife()==0){
            std::vector<Object *>::iterator it=m_object.begin()+i;
            m_object.erase(it);
            }
            i+=1;
        }
    }
    if(firstBall == false && secondBall == true && thirdBall == false) {
        m_ball[0]->Display();
        int i=0;
        for(Object * obj : m_object) {
            contact(m_ball[0],obj);
            if (obj->getLife()==0){
            std::vector<Object *>::iterator it=m_object.begin()+i;
            m_object.erase(it);
            }
            i+=1;
        }
    }
    if(firstBall == false && secondBall == false && thirdBall == true) {
        m_ball[0]->Display();
        int i=0;
        for(Object * obj : m_object) {
            contact(m_ball[0],obj);
            if (obj->getLife()==0){
            std::vector<Object *>::iterator it=m_object.begin()+i;
            m_object.erase(it);
            }
            i+=1;
        }
    }

    for(Object * obj : m_object) {
    obj->Display();}

    displayTime();
}


void MyGLWidget::contact(Ball *boulet,Object *obj)
{
    float dy=boulet->getdy();
    float dx=boulet->getdx();

    if(obj->getName()=="Wall") {
        if (boulet->getX()+boulet->getR() > ORTHO_DIM*ASPECT_RATIO){
            boulet->setdx(-dx);//droit

        }
        if (boulet->getX()-boulet->getR() < -ORTHO_DIM*ASPECT_RATIO){
            boulet->setdx(-dx);
            //gauche
        }

        if (boulet->getY()+boulet->getR() > ORTHO_DIM){
            boulet->setdy(-dy);//haut
        }

        if(boulet->getY()+boulet->getR() < -ORTHO_DIM) {
            if(m_ball.size() != 0)  {
                if(boulet->getId() == 1) {
                    firstBall = false;
                    secondBall = true;
                    thirdBall = false;
                }
                if(boulet->getId() == 2) {
                    firstBall = false;
                    secondBall = false;
                    thirdBall = true;
                }
                if(boulet->getId() == 3) {
                    firstBall = false;
                    secondBall = false;
                    thirdBall = false;
                    QMessageBox msgBox;
                    msgBox.setText("Vous avez perdu !");
                    msgBox.setInformativeText("Voulez vous recommencer ?");
                    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
                    msgBox.setDefaultButton(QMessageBox::Yes);
                    int ret = msgBox.exec();

                    switch (ret) {
                      case QMessageBox::Yes:
                          Again();
                          break;
                      case QMessageBox::No:
                          window()->close();
                          break;
                      default:
                          break;
                    }
                }
                std::vector<Ball *>::iterator it = m_ball.begin();
                m_ball.erase(it);
            }
        }
    }

//
    if(obj->getName()=="Brick") {
        if(((boulet->getY()-boulet->getR())<=(obj->getInfo("y")+obj->getInfo("h"))) && (((boulet->getY()+boulet->getR())<=obj->getInfo("y")+obj->getInfo("h"))) && ((boulet->getX()-boulet->getR())<=(obj->getInfo("x")+obj->getInfo("h"))) && ((boulet->getX()+boulet->getR())>=obj->getInfo("x")))
        {

              // Fait le rebond
              dy=-dy;

              // Oriente différemment la balle selon le contact avec la barre
              dx=(boulet->getX()-(obj->getInfo("x")+obj->getInfo("w")/2))/10;

              // Met une valeur max et une min
              if(dx>0.025)  dx=0.025;
              if(dx<-0.025) dx=-0.025;
              obj->LoseLife();

              boulet->setdx(dx);
              boulet->setdy(dy);



          }}


    if(obj->getName()=="Puck") {
        if(boulet->getY()-boulet->getR() <= obj->getInfo("posy")+obj->getInfo("posh")) { //Au niveau du palet
            /*qDebug() << boulet->getX()-boulet->getR();
            qDebug() << obj->getInfo("posx")-obj->getInfo("posw");
            qDebug() << boulet->getX()+boulet->getR();
            qDebug() << obj->getInfo("posx")+obj->getInfo("posw");*/
            if(boulet->getX()-boulet->getR() < 0) { //Venant de gauche
                if(( obj->getInfo("posx")-obj->getInfo("posw")+42 >= boulet->getX()-boulet->getR()) && (boulet->getX()+boulet->getR() >= obj->getInfo("posx")+obj->getInfo("posw")-21)) {
                    boulet->setdy(-dy);
                }
            }
            if(boulet->getX()-boulet->getR() > 0) { //Venant de droite
                if((obj->getInfo("posx")+obj->getInfo("posw") >= boulet->getX()-boulet->getR()-21) && (boulet->getX()+boulet->getR()-21 >= obj->getInfo("posx")-obj->getInfo("posw"))) {
                    boulet->setdy(-dy);
                }
            }
        }
    }

    boulet->setPos();
}

// Fonction de gestion d"interactions clavier
void MyGLWidget::keyPressEvent(QKeyEvent * event)
{
    switch(event->key())
    {
        // Sortie de l"application
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
            // Ignorer l"evenement
            event->ignore();
            return;
        }
    }

    // Acceptation de l"evenement et mise a jour de la scene
    event->accept();

}

void MyGLWidget::Again() {

    m_ball.clear();
    m_object.clear();

    ball1_ = new Ball(0.,-0.75,1.5,1); //balle qui se fait éléminer de suite
    ball2_ = new Ball(3.5,-0.75,1.5,1);
    ball3_ = new Ball(-3.5,-0.75,1.5,2);
    ball4_ = new Ball(0.,-0.75,1.5,3);

    puck_ = new Puck("Puck",1);
    walls_ = new Wall("Wall",1);

    m_ball.push_back(ball1_);
    m_ball.push_back(ball2_);
    m_ball.push_back(ball3_);
    m_ball.push_back(ball4_);
    m_object.push_back(puck_);

    for (int i=0;i<10;i++){
        for(int j=0;j<5;j++){
        brick_= new brick("Brick",i+j);
        brick_->setY(-j*10.);
            brick_->setX(i*17);

           m_object.push_back(brick_);
        }
    }

    m_object.push_back(walls_);

    firstBall = true;
}

void MyGLWidget::displayTime() {
    QString time = QString::number(m_TimeElapsed);
    QFont maFonte("Arial", 20, QFont::DemiBold);
    glColor3f(0,0,0);
    renderText(-5,15,0,"Time :" + time,maFonte);
}
