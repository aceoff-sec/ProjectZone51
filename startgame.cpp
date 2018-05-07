#include "startgame.h"
#include "ui_startgame.h"
#include <QDebug>
#include <fstream>

StartGame::StartGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartGame)
{
    ui->setupUi(this);
    QFile file("scores.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }
    QTextStream in(&file);
    QString line;
    while(!in.atEnd()) {
        line = in.readLine();
        ui->textEdit->append(line);
    }
}

StartGame::~StartGame()
{
    delete ui;
}

void StartGame::start() {
    QString player = ui->lineEdit->text();
    float size = ui->spinBox->value();
    MyGLWidget::setSize(size);
    MyGLWidget::setName(player);
    close();
}



