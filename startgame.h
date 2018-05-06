#ifndef STARTGAME_H
#define STARTGAME_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class StartGame;
}

class StartGame : public QDialog
{
    Q_OBJECT

public:
    explicit StartGame(QWidget *parent = 0);
    ~StartGame();

private:
    Ui::StartGame *ui;
private slots:
    void start();
};

#endif // STARTGAME_H
