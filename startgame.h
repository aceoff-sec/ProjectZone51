#ifndef STARTGAME_H
#define STARTGAME_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class StartGame;
}

// Classe qui ouvre une fenêtre de dialogue pour choisir la taille du palet et voir le tableau des scores (Nicolas)
class StartGame : public QDialog
{
    Q_OBJECT
public:
    explicit StartGame(QWidget *parent = 0); // Constructeur explicite
    ~StartGame(); // Destructeur
private:
    Ui::StartGame *ui; // Lien vers le ui
private slots:
    void start(); // Si on appuie sur "Ok", la fenêtre se ferme et on peut commencer à jouer
};

#endif // STARTGAME_H
