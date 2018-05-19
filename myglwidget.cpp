#include "myglwidget.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <fstream>

// Declarations des constantes
const unsigned int WIN_WIDTH  = 900;
const unsigned int WIN_HEIGHT = 500;
const float ASPECT_RATIO      = static_cast<float>(WIN_WIDTH) / WIN_HEIGHT;
const float ORTHO_DIM         = 50.0f;
Puck* MyGLWidget::puck_;
bool MyGLWidget::space= false;
QString MyGLWidget::name_;



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
    glClearColor(0.f, 0.f, 0.f,0.f);
    //Lumière
   // glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    // Activation du zbuffer

    glEnable(GL_LIGHTING);
        //Premiere lampe
        GLfloat param[]={1.,1.,1.,1.0};
        glLightfv(GL_LIGHT0, GL_AMBIENT_AND_DIFFUSE,param);
        GLfloat position[]={0.0,0.0,1.,0.0};
        glLightfv(GL_LIGHT0,GL_POSITION,position);
        //Deuxieme lampe
        /*glLightfv(GL_LIGHT1, GL_AMBIENT_AND_DIFFUSE,param);
        GLfloat position2[]={-20.0,0.0,-40.,0.0};
        glLightfv(GL_LIGHT0,GL_POSITION,position2);*/
    glEnable(GL_LIGHT0);
    //glEnable(GL_LIGHT1);

        glEnable(GL_DEPTH_TEST);
    //ajout
    ball1_ = new Ball(-5,-5,1.5,1);
    ball2_ = new Ball(-5,-5,1.5,2);
    ball3_ = new Ball(-5,-5,1.5,3);
    puck_ = new Puck("Puck",50);
    walls_ = new Wall("Wall",51);
    m_ball.push_back(ball1_);
    m_ball.push_back(ball2_);
    m_ball.push_back(ball3_);
    nbBrick = 0;
    score = 0;
    level = 1;

    createBrick();

    m_object.push_back(puck_);
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
    // Definition de la position de la camera
    gluLookAt(0,-2,22,0,0,0,0,1,0);
    glLoadIdentity();
    glEnable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
    //glColor3f(1.0f,1.0f,1.0f);
    GLfloat param1[]={1.,1.,1.,1.0};
    glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,param1);

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

        for(Object * obj : m_object) {
            contact(m_ball[0],obj);
        }
    }
    if(firstBall == false && secondBall == true && thirdBall == false) {
        m_ball[0]->Display();
        for(Object * obj : m_object) {
            contact(m_ball[0],obj);
        }
    }
    if(firstBall == false && secondBall == false && thirdBall == true) {
        m_ball[0]->Display();
        for(Object * obj : m_object) {
            contact(m_ball[0],obj);
        }
    }

    for(Object * obj : m_object) {
    obj->Display();}

    displayInfo();
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
            nbBalls--;
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
                    save(name_,(float)score);
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
    if(obj->getName()=="Brick" && obj->getLife()!=0) {
        if(boulet->getY()-boulet->getR()<=obj->getInfo("y")+obj->getInfo("h") && boulet->getY()+boulet->getR()>=obj->getInfo("y") ) {

                if (boulet->getX()+boulet->getR()>=obj->getInfo("x") && boulet->getX()-boulet->getR()<=obj->getInfo("x")+obj->getInfo("w")){
                     // Fait le rebond
                    dy=-dy;

                    // Oriente différemment la balle selon le contact avec la barre
                    dx=(boulet->getX()-(obj->getInfo("x")+obj->getInfo("w")/2))/10;

                    // Met une valeur max et une min
                    if(dx>0.025)  dx=0.025;
                    if(dx<-0.025) dx=-0.025;
                    obj->LoseLife();
                    nbBrick--;
                    if(obj->getLife() == 0) { score=score+obj->getPoint(); }
                    if(nbBrick == 0 && level ==1) {
                        boulet->setx(-5);
                        boulet->sety(-5);
                        level++;
                        createBrick();
                    }
                    if(nbBrick == 0 && level ==2) {
                        boulet->setx(-5);
                        boulet->sety(-5);
                        level++;
                        createBrick();
                    }
                    if(nbBrick == 0 && level ==3) {
                        firstBall = false;
                        secondBall = false;
                        thirdBall = false;

                        QMessageBox msgBox;
                        save(name_,(float)score);
                        msgBox.setText("Vous avez gagné !");
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


                    boulet->setdx(dx);
                    boulet->setdy(dy);

          }}
    }


    if(obj->getName()=="Puck") {
        if(boulet->getY()-boulet->getR() <= obj->getInfo("posy")+obj->getInfo("posh")) { //Au niveau du palet

            if(boulet->getX()-boulet->getR() < 0) { //Venant de gauche
                if(( obj->getInfo("posx")-obj->getInfo("posw")+42+obj->getSize() >= boulet->getX()-boulet->getR()) && (boulet->getX()+boulet->getR() >= obj->getInfo("posx")+obj->getInfo("posw")-21-obj->getSize())) {
                    dx=(boulet->getX()-(obj->getInfo("posx")+obj->getInfo("posw")/2))/10;
                    if(dx>0.025)  dx=0.025;
                    if(dx<-0.025) dx=-0.025;
                    boulet->setdx(dx);
                    boulet->setdy(-dy);
                }
            }
            if(boulet->getX()-boulet->getR() > 0) { //Venant de droite
                if((obj->getInfo("posx")+obj->getInfo("posw") >= boulet->getX()-boulet->getR()-21-obj->getSize()) && (boulet->getX()+boulet->getR() >= obj->getInfo("posx")-obj->getInfo("posw"))) {
                    dx=(boulet->getX()-(obj->getInfo("posx")+obj->getInfo("posw")/2))/10;
                    if(dx>0.025)  dx=0.025;
                    if(dx<-0.025) dx=-0.025;
                    boulet->setdx(dx);
                    boulet->setdy(-dy);

                }
            }
        }
    }

    if(space) {
       boulet->setPos();
    }
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
            moveLeft();
            break;
        }

        // Mouvement du palet à droite
        case Qt::Key_Right:
        {
            moveRight();
            break;
        }

        case Qt::Key_Space:
        {
            if(firstspace) {
                space = !space;
                firstspace = !firstspace;
                break;
            }
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
    touched.clear();
    ball1_ = new Ball(0.,-0.75,1.5,1); //balle qui se fait éléminer de suite
    ball2_ = new Ball(3.5,-0.75,1.5,1);
    ball3_ = new Ball(-3.5,-0.75,1.5,2);
    ball4_ = new Ball(0.,-0.75,1.5,3);

    puck_ = new Puck("Puck",50);
    walls_ = new Wall("Wall",51);

    m_ball.push_back(ball1_);
    m_ball.push_back(ball2_);
    m_ball.push_back(ball3_);
    m_ball.push_back(ball4_);


    for (int i=0;i<10;i++){
        for(int j=0;j<5;j++){
        brick_= new brick("Brick",i+j,image_b);
        brick_->setY(-j*10.);
            brick_->setX(i*17);

           m_object.push_back(brick_);
           nbBrick++;
        }
    }

    m_object.push_back(puck_);
    m_object.push_back(walls_);

    firstBall = true;
    m_TimeElapsed = 0;
    score = 0;
    level = 1;
    nbBalls = 3;
    space = !space;
    firstspace = !firstspace;
    firstTime = !firstTime;
}

void MyGLWidget::displayInfo() {
    time_ = QString::number((int)m_TimeElapsed);
    score_ = QString::number(score);
    level_ = QString::number(level);
    nbBalls_ = QString::number(nbBalls);
    glColor3f(1,1,1);
    QFont font("Times",8,QFont::Bold);
    QFont font2("Times",20,QFont::Bold);
    renderText(302,320,"Score :" +score_,font);
    renderText(380,320,"Nb balls :"+nbBalls_, font);
    renderText(725,320,"Level :" +level_,font);
    if(!space) {
        renderText(245,260,"Press Space to begin",font2);
        renderText(3,320,"Time : 0",font);
    }
    else {
        if(firstTime) {
            m_TimeElapsed =0;
            firstTime = !firstTime;
        }
        renderText(3,320,"Time :" + time_,font);
    }

}

bool MyGLWidget::Nottouched(Object *obj,std::vector<int> vect){
    bool val=true;
    for(int i : vect) {
        if(obj->getId()==vect[i]){val=false;}
    }
    return val;
}

void MyGLWidget::moveLeft() {
    if(space) {
        puck_->moveLeft();
    }
}

void MyGLWidget::moveRight() {
    if(space) {
        puck_->moveRight();
    }
}

void MyGLWidget::moveStop() {
    if(space) {
        puck_->moveStop();
    }
}
void MyGLWidget::createBrick() {
    for (int i=0;i<10;i++){
        for(int j=0;j<5;j++){
            if((j==2 || j==4) && level==2) {
                brick_->setR(250);
                brick_->setV(250);
                brick_->setB(0);
                brick_->setPoint(3);
                brick_->setVie(2);
            }
            if((j==2 || j==4) && level==3) {
                brick_->setR(250);
                brick_->setV(0);
                brick_->setB(250);
                brick_ ->setPoint(5);
                brick_->setVie(3);
            }
            brick_= new brick("Brick",i+j,image_b);
            brick_->setY(-j*10.);
            brick_->setX(i*17);

            m_object.push_back(brick_);
            nbBrick++;
        }
    }
    updateGL();
}

void MyGLWidget::setSize(float size) {
    puck_->setSize(size);
}

void MyGLWidget::save(QString player, float val) {
    if(!player.toStdString().empty()) {
        std::fstream os("scores.txt",std::ios::app);
        os<<player.toStdString().c_str();
        os<< " ";
        os<<std::to_string((int)val).c_str();
        os<<"\n";
        os.close();
    }
}
