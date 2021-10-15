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
#include <QTimer>

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


public slots:
    void formula();


private slots:
    void on_radioButton_3_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    vector<Planetas *> planets;
    QGraphicsEllipseItem *Sol;

    float Masa=0;
    float PosicionFX=0,PosicionFY=0;

    QTimer *timer = new QTimer(this);
};
#endif // MAINWINDOW_H
