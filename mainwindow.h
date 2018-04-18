#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "opencv2/opencv.hpp"
#include <QMainWindow>
#include <QWidget>
#include <QTimer>
#include <iostream>
#include <QString>
#include "myglwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    // Pour utiliser la caméra
    cv::VideoCapture * webCam_;
    // Taille de la capture
    int frameWidth=320;
    int frameHeight=240;
    // Taille du rectangle vert
    int subImageWidth=200;
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
    void capture();

};

#endif // MAINWINDOW_H
