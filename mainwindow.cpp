#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int widthScene = ui->graphicsView->width()-5;
    int heightScene = ui->graphicsView->height()-5;
    scene = new QGraphicsScene(-widthScene/2,-heightScene/2,ui->graphicsView->width(),ui->graphicsView->height());
    ui->graphicsView->setScene(scene);

    //scene->addEllipse(0,0,500,500);
    lectu();


    connect( timer, SIGNAL(timeout()),this, SLOT(formula()));
    timer->start(5);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::lectu()
{
    string contenido;

    static int cont=0;

    float PxS=0,PyS=0;

    ifstream archi;

    archi.open("../SistemaSolar/BD/Sistema.txt");

    if (!archi.is_open())
    {
      cout << "Error abriendo el archivo" << endl;
      exit(1);
    }
    archi >> contenido;

    string linea;

    array <float,7> elementos{};

    while(!archi.eof()){

        string variable;

        getline(archi,linea);


        Planetas *plan;

        if (linea ==""){
            linea=contenido;
        }


        int longitud =linea.length(),posicion=0;
        for (int i =0;i < longitud+1;i++){
            //cout<<linea[i]<<endl;
            if (linea[i] != '\t' and i<longitud){
                variable+=linea[i];
            }
            else{
                if(variable[0] <= 57 and variable[0]>=45){
                    elementos[posicion] = stof(variable);
                    posicion++;
                    variable="";
                }
            }
        }
        if(cont == 1){
            Sol = scene->addEllipse(-elementos[4]*Escala,-elementos[4]*Escala,(elementos[4]*2)*0.03,(elementos[4]*2)*0.03);
            Masa=elementos[3];
            PxS=elementos[1];
            PyS=elementos[2];
        }
        else if(cont>1){
            plan= new Planetas(elementos[1],elementos[2],elementos[4],elementos[5],elementos[6],Masa,PxS,PyS);
            scene->addItem(plan);
            planets.push_back(plan);
        }
        cont++;
    }
    archi.close();
}

void MainWindow::formula()
{
    for (auto planeta : planets){

        planeta->CalAngulo();

        int tiempo = planeta->getTime();
        float PoX = planeta->getPosX(), PoY = planeta->getPosY();
        float VX = planeta->getVfX(), VY = planeta->getVfY();
        float Ax = planeta->getAcX(),Ay = planeta->getAcY();

        PosicionFX = PoX + (VX * tiempo) + ((Ax*pow(tiempo,2))/2);
        PosicionFY = PoY + (VY * tiempo) + ((Ay*pow(tiempo,2))/2);

        planeta->setPos(PosicionFX*Escala,-PosicionFY*Escala);

        planeta->setPosX(PosicionFX);
        planeta->setPosY(PosicionFY);

        planeta->setVox(VX);
        planeta->setVoy(VY);




    }
}



void MainWindow::on_radioButton_3_clicked()
{
   timer->start(10);
}

void MainWindow::on_radioButton_2_clicked()
{
    timer->start(5);
}

void MainWindow::on_radioButton_clicked()
{
    timer->start(1);
}
