#include "startgame.h"
#include "ui_startgame.h"
#include <QDebug>
#include <fstream>

StartGame::StartGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartGame)
{
    ui->setupUi(this);
    std::ifstream file("scores.txt");
    std::string text;
    while(std::getline(file,text,';')) {
        file >> text;
        std::cout<<text;
        ui->textEdit->append(QString::fromStdString(text)+"\n");
    }
    file.close();
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



