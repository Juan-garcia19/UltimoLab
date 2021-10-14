#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int widthScene = ui->graphicsView->width()-5;
    int heightScene = ui->graphicsView->height()-5;
    scene = new QGraphicsScene(-widthScene/2,-heightScene/2,ui->graphicsView->width()-5,ui->graphicsView->height()-5);
    ui->graphicsView->setScene(scene);

    //Sol = scene->addEllipse(0,0,9,9);
    lectu();



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::lectu()
{
    string contenido;

    static int cont=0;

    ifstream archi;

    archi.open("../SistemaSolar/BD/Sistema.txt");

    if (!archi.is_open())
    {
      cout << "Error abriendo el archivo" << endl;
      exit(1);
    }
    archi >> contenido;

    string linea;

    array <int,7> elementos{};

    while(!archi.eof()){

        string variable;

        getline(archi,linea);


        Planetas *plan;

        if (linea ==""){
            linea=contenido;
        }


        int longitud =linea.length(),posicion=0;
        for (int i =0;i < longitud;i++){
            //cout<<linea[i]<<endl;
            if (linea[i] != '\t' ){
                variable+=linea[i];
            }
            else{
                if(variable[0] <= 57 and variable[0]>=45){
                    elementos[posicion]=stoi(variable);
                    posicion++;
                    variable="";
                }
            }
        }
        if(cont == 1){
            Sol = scene->addEllipse(elementos[1],elementos[2],elementos[4]*Escala,elementos[4]*Escala);
            Masa=elementos[2];
        }
        else if(cont>1){
            plan= new Planetas(elementos[1],elementos[2],elementos[4],elementos[5],elementos[6]);
            scene->addItem(plan);
            planets.push_back(plan);
        }
        cont++;
    }
    archi.close();
}


