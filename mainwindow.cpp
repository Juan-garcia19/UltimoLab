#include "mainwindow.h"
#include "ui_mainwindow.h"

/*para esta practica se deben tener en cuenta varios aspectos, por parte de alejar o acercar la pantalla pues no
 * supe como hacerla, intente verlo en clases pero no hay grabaciones. para el area del txt no pude escalar
 * correctamente el sistema solar, pero cuando se prueba con datos bien escalados como el ejemplo 1 y 2 funciona perfecto
 *
*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int widthScene = ui->graphicsView->width()-5;
    int heightScene = ui->graphicsView->height()-5;
    scene = new QGraphicsScene(-widthScene/2,-heightScene/2,ui->graphicsView->width(),ui->graphicsView->height());
    ui->graphicsView->setScene(scene);

    //ui->verticalSlider->valueChanged(ui->verticalSlider->value());

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
            QPen pen;
            QBrush brush1(QColor(255,255,0));
            Sol = scene->addEllipse(-elementos[4]*Escala,-elementos[4]*Escala,(elementos[4]*2)*Escala,(elementos[4]*2)*Escala,pen,brush1);
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

void MainWindow::on_pushButton_clicked()
{
    for (auto planeta : planets){
        planeta->setTime(1);
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    for (auto planeta : planets){
        planeta->setTime(0);
    }

}

void MainWindow::on_verticalSlider_valueChanged(int value)
{
    int widthScene = ui->graphicsView->width()-5;
    int heightScene = ui->graphicsView->height()-5;
   // scene = new QGraphicsScene(-widthScene/2,-heightScene/2
    if (value==1){
        ui->graphicsView->setSceneRect(-widthScene/2,-heightScene/2,1000,10000);
    }
    else if(value == 0){
        ui->graphicsView->setSceneRect(-widthScene/2,-heightScene/2,ui->graphicsView->width(),ui->graphicsView->height());
    }

    else if(value == -1){
        ui->graphicsView->setSceneRect(-widthScene/2,-heightScene/2,300,300);
    }

}
