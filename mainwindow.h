#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "opencv2/opencv.hpp"
#include <QMainWindow>
#include <QWidget>
#include <QTimer>
#include <iostream>
#include <QString>
#include "myglwidget.h"
#include "startgame.h"
#include <QThread>

namespace Ui {
class MainWindow;
}
// Classe qui permet de gérer la caméra et de la placer dans le QLabel (Nicolas)
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0); // Constructeur explicite du ui
    ~MainWindow(); // Destructeur
private:
    Ui::MainWindow *ui; // Lien vers le ui
    cv::VideoCapture * webCam_; // Pour utiliser la caméra
    // Taille de la capture
    int frameWidth=320;
    int frameHeight=240;
    // Taille du rectangle vert
    int subImageWidth=150;
    int subImageHeight=100;
    // Taille du motif
    int templateWidth=25;
    int templateHeight=25;
    // Test si c'est la 1ère Frame
    bool noFirstFrame = false;
    // On initialise maxLoc, nécessaire à calculer un point
    cv::Point maxLoc = cv::Point(0,0);
    // On définit les différentes objet Mat pour les captures
    cv::Mat frame1,frame2,frameRect1,frameRect2;
    // Stocker le résultat de matchTemplate
    cv::Mat resultImage;
private slots:
    void capture(); // Permet de rendre la caméra active et de gérer le mouvement du palet selon le déplacement horizontal
    void game(); // Permet d'appeler la fenêtre de dialogue permettant de choisir le taille du palet et de voir le tableau des scores
};

#endif // MAINWINDOW_H
