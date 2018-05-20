#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Ouvre la caméra par défault
    webCam_=new cv::VideoCapture(0);

    webCam_->set(CV_CAP_PROP_FRAME_WIDTH,500);
    webCam_->set(CV_CAP_PROP_FRAME_HEIGHT,50);
    // Crée le résultat image de matchTemplate
    int result_cols =  frameHeight-templateWidth  + 1;
    int result_rows = frameWidth-templateHeight + 1;
    resultImage.create( result_cols, result_rows, CV_32FC1 );
    resultImage2.create( result_cols, result_rows, CV_32FC1 );

    // On utilise un timer toutes les milisecondes, il appelle le slot capture
    QTimer *timer= new QTimer();
    QTimer::singleShot(1,this,SLOT(game()));
    connect(timer,SIGNAL(timeout()),this,SLOT(capture()));
    timer->start(1);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete webCam_;
}

void MainWindow::capture()
{
    if (webCam_->isOpened()) {

        if (webCam_->read(frame2)) {   // Capture une frame

            // Rectangle vert dans lequel on repère la main
            cv::Rect workingRect((-40)+(frameWidth-subImageWidth)/2,frameHeight/2+(frameHeight/2-subImageHeight)/2,subImageWidth,subImageHeight);
            // Rectangle motif que l'on compare
            cv::Rect templateRect((workingRect.width-templateWidth)/2,(workingRect.height-templateHeight)/2,templateWidth,templateHeight);
            // Point central du vecteur
            cv::Point workingCenter(workingRect.x+subImageWidth/2,workingRect.y+subImageHeight/2);

            // Rectangle vert dans lequel on repère la main
            cv::Rect workingRect2(40+(frameWidth-subImageWidth)/2,frameHeight/2+(frameHeight/2-subImageHeight)/2,subImageWidth,subImageHeight);
            // Rectangle motif que l'on compare
            cv::Rect templateRect2((workingRect2.width-templateWidth)/2,(workingRect2.height-templateHeight)/2,templateWidth,templateHeight);
            // Point central du vecteur
            cv::Point workingCenter2(workingRect2.x+subImageWidth/2,workingRect2.y+subImageHeight/2);

            // Mirror effect
            cv::flip(frame2,frame2,1);
            // Extract working rect in frame2 and convert to gray
            cv::cvtColor(cv::Mat(frame2,workingRect),frameRect2,cv::COLOR_BGR2GRAY);
            // Extract working rect in frame2 and convert to gray
            cv::cvtColor(cv::Mat(frame2,workingRect2),frameRect2,cv::COLOR_BGR2GRAY);

            if(noFirstFrame) {
                // Extract template image in frame1
                cv::Mat templateImage(frameRect1,templateRect);
                // Do the Matching between the working rect in frame2 and the templateImage in frame1
                cv::matchTemplate( frameRect2, templateImage, resultImage, cv::TM_CCORR_NORMED );
                // Localize the best match with minMaxLoc (c'est-à-dire la zone qui match le plus pour savoir dans quelle direction le vecteur doit aller)
                double minVal; double maxVal; cv::Point minLoc;
                cv::minMaxLoc( resultImage, &minVal, &maxVal, &minLoc, &maxLoc);

                // Extract template image in frame1
                cv::Mat templateImage2(frameRect1,templateRect2);
                // Do the Matching between the working rect in frame2 and the templateImage in frame1
                cv::matchTemplate( frameRect2, templateImage2, resultImage2, cv::TM_CCORR_NORMED );
                // Localize the best match with minMaxLoc (c'est-à-dire la zone qui match le plus pour savoir dans quelle direction le vecteur doit aller)
                double minVal2; double maxVal2; cv::Point minLoc2;
                cv::minMaxLoc( resultImage2, &minVal2, &maxVal2, &minLoc2, &maxLoc);
            }
            // Compute the translation vector between the origin and the matching rect
            cv::Point vect(maxLoc.x-templateRect.x,maxLoc.y-templateRect.y); // Vecteur vitesse dont on va utiliser les coordonnées pour bouger l'objet
            // Compute the translation vector between the origin and the matching rect
            cv::Point vect2(maxLoc.x-templateRect2.x,maxLoc.y-templateRect2.y); // Vecteur vitesse dont on va utiliser les coordonnées pour bouger l'objet

            // Draw green rectangle and the translation vector
            cv::rectangle(frame2,workingRect,cv::Scalar( 0, 255, 0),2);
            cv::Point p(workingCenter.x+vect.x,workingCenter.y+vect.y);
            cv::arrowedLine(frame2,workingCenter,p,cv::Scalar(255,255,255),2);


            // Draw green rectangle and the translation vector
            cv::rectangle(frame2,workingRect2,cv::Scalar(255, 0, 0),2);
            cv::Point p2(workingCenter2.x+vect2.x,workingCenter2.y+vect2.y);
            cv::arrowedLine(frame2,workingCenter2,p2,cv::Scalar(255,255,255),2);

            // Swap matrixes
            swap(frameRect1,frameRect2);

            // Convert to Qt image
            QImage img= QImage((const unsigned char*)(frame2.data),frame2.cols,frame2.rows,QImage::Format_RGB888);
            // Display on label
            ui->imageLabel_->setPixmap(QPixmap::fromImage(img));
            // Resize the label to fit the image
            //ui->imageLabel_->resize(ui->imageLabel_->pixmap()->size());

            noFirstFrame=true;

            if(MyGLWidget::getSpace()) {
                if((vect.x+vect2.x)/2 < -5 && ((vect.y+vect2.y)/2 < 0.5 || (vect.y+vect2.y)/2 > -(0.5))) {
                    MyGLWidget::moveLeft();
                }
                if((vect.x+vect2.x)/2 > 5 && ((vect.y+vect2.y)/2 < 0.5 || (vect.y+vect2.y)/2 > -(0.5)) )  {
                    MyGLWidget::moveRight();
                }
                if((vect.y+vect2.y)/2 > 10 && ((vect.x+vect2.x)/2 < 3 || (vect.x+vect2.x)/2 > -3)) {
                    MyGLWidget::moveStop();
                }
            }
        }
        else {

        }

    }
}

void MainWindow::game() {
    StartGame st;
    st.exec() ;
}
