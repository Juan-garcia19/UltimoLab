#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define Escala 0.03

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMainWindow>

#include <fstream>
#include <iostream>
#include <vector>

#include "planetas.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void lectu();


private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    vector<Planetas *> planets;
    QGraphicsEllipseItem *Sol;

    int Masa=0;
};
#endif // MAINWINDOW_H
