#include "cframe.h"
#include "ui_cframe.h"
#include <QPixmap>

CFrame::CFrame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CFrame)
{



    disponiblesSize=5;
    PAltaSize=1;
    PMediaSize=1;
    PBajaSize=1;
    ui->setupUi(this);
    Predefinido();
    MostrarDisponibles();
    on_tabWidget_Listas_tabBarClicked(0);
    QPixmap pix(":/Edwin.jpeg");
    ui->Edwin->setPixmap(pix.scaled(ui->Edwin->width(),ui->Edwin->height(),Qt::KeepAspectRatio));
    QPixmap pix2(":/Julio.jpeg");
    ui->Julio->setPixmap(pix2.scaled(ui->Julio->width(),ui->Julio->height(),Qt::KeepAspectRatio));
    QPixmap pix3(":/Indira.jpeg");
    ui->Indira->setPixmap(pix3.scaled(ui->Indira->width(),ui->Indira->height(),Qt::KeepAspectRatio));
    QPixmap pix4(":/Josue.jpeg");
    ui->Josue->setPixmap(pix4.scaled(ui->Josue->width(),ui->Josue->height(),Qt::KeepAspectRatio));
}

CFrame::~CFrame()
{
    delete ui;
}

void CFrame::Predefinido()
{
    L.insertarAlFinal( new Casa ("Cas001","Col. Miraflores Sur","Naranja",2,6,4,0,1800000 ));
    L.insertarAlFinal( new Casa ("Cas002","Barrio el Calvario","Verde",2,4,2,0,1200000 ));
    L.insertarAlFinal( new Casa ("Cas003","Lomas de Toncontín","Verde",1,5,4,2,1000000 ));
    L.insertarAlFinal( new Casa ("Cas004","Col. Kennedy","Cafe",1,3,2,2,1000000 ));
    L.insertarAlFinal( new Casa ("Cas005","Col. San Francisco","Morado",2,4,3,2,800000 ));
    L.insertarAlFinal( new Casa ("Cas006","Villa Toscana","Blanco",1,2,2,2,1200000 ));
    L.insertarAlFinal( new Casa ("Cas007","Col. Nueva Capital","Negro",2,5,5,2,2000000 ));
    L.insertarAlFinal( new Casa ("Cas008","Santa Lucia","Blanco",1,5,3,2,1000000 ));
    L.insertarAlFinal( new Casa ("Cas009","Lomas del Guijarro","Blanco",6,8,4,2,3500000 ));
    L.insertarAlFinal( new Casa ("Cas010","Col. Los Hidalgos","Verde",1,3,1,2,2000000 ));
    L.insertarAlFinal( new Casa ("Cas011","Col. Villa Foresta","Amarillo",1,2,2,2,900000 ));
    L.insertarAlFinal( new Casa ("Cas012","Col. Kennedy","Blanco Bueso",1,4,3,3,1200000 ));
    L.insertarAlFinal( new Casa ("Cas013","Valle de Angeles","Blanco",2,4,2,2,2500000 ));
}

int CFrame::ContarDisponibles()
{
    int C = 0;

    ActP = L.primeroPtr;
    for( ; ActP!=0 ; C++ ){
        ActP = ActP->sigPtr;
    }
    return C;
}

int CFrame::ContarPAlta()
{
    int C = 0;

    ActP = ColaPAlta.PrimP;
    for( ; ActP!=0 ; C++ ){
        ActP = ActP->sigPtr;
    }
    return C;
}

int CFrame::ContarPMedia()
{
    int C = 0;

    ActP = ColaPMedia.PrimP;
    for( ; ActP!=0 ; C++ ){
        ActP = ActP->sigPtr;
    }
    return C;
}

int CFrame::ContarPBaja()
{
    int C = 0;

    ActP = ColaBaja.PrimP;
    for( ; ActP!=0 ; C++ ){
        ActP = ActP->sigPtr;
    }
    return C;
}




void CFrame::MostrarDisponibles()
{
tabPermission(1);
    ui->tableWidget_disponibles->clear();

    ui->tableWidget_disponibles->setColumnCount(9);
    ui->tableWidget_disponibles->setRowCount( ContarDisponibles() );

    ui->tableWidget_disponibles->setHorizontalHeaderLabels( QStringList()<<"Posición"<<"Código"<<"Dirección"<<"Color"<<"Niveles"<<"Habitaciones"<<"Baños"<<"Parqueos"<<"Precio");

    int P=0;
    disponiblesSize = 0;
    for ( ActP=L.primeroPtr ; ActP!=0 ; ActP=ActP->sigPtr, P++ ) {
        disponiblesSize ++;
        QTableWidgetItem *Pos = new QTableWidgetItem( QString::number(P) );
        QTableWidgetItem *Cod = new QTableWidgetItem( QString::fromStdString( ActP->datos->getCodigo() ) );
        QTableWidgetItem *Dir = new QTableWidgetItem( QString::fromStdString( ActP->datos->getDireccion() ) );
        QTableWidgetItem *Col = new QTableWidgetItem( QString::fromStdString( ActP->datos->getColor() ) );
        QTableWidgetItem *Niv = new QTableWidgetItem( QString::number(ActP->datos->getNivel() ) );
        QTableWidgetItem *Hab = new QTableWidgetItem( QString::number( ActP->datos->getHabitacion() ) );
        QTableWidgetItem *Ba = new QTableWidgetItem( QString::number( ActP->datos->getBanio() ) );
        QTableWidgetItem *Par = new QTableWidgetItem( QString::number( ActP->datos->getParqueo() ) );
        QTableWidgetItem *Pre = new QTableWidgetItem( QString::number( ActP->datos->getPrecio() ) );


        ui->tableWidget_disponibles->setItem(P,0,Pos);
        ui->tableWidget_disponibles->setItem(P,1,Cod);
        ui->tableWidget_disponibles->setItem(P,2,Dir);
        ui->tableWidget_disponibles->setItem(P,3,Col);
        ui->tableWidget_disponibles->setItem(P,4,Niv);
        ui->tableWidget_disponibles->setItem(P,5,Hab);
        ui->tableWidget_disponibles->setItem(P,6,Ba);
        ui->tableWidget_disponibles->setItem(P,7,Par);
        ui->tableWidget_disponibles->setItem(P,8,Pre);

    }
}

void CFrame::MostrarPAlta()
{
    ui->tableWidget_PAlta->clear();

    ui->tableWidget_PAlta->setColumnCount(9);
    ui->tableWidget_PAlta->setRowCount( ContarPAlta() );

    ui->tableWidget_PAlta->setHorizontalHeaderLabels( QStringList()<<"Posición"<<"Código"<<"Dirección"<<"Color"<<"Niveles"<<"Habitaciones"<<"Baños"<<"Parqueos"<<"Precio");

    int P=0;
    PAltaSize =0;
    for ( ActP=ColaPAlta.PrimP ; ActP!=0 ; ActP=ActP->sigPtr, P++ ) {
        PAltaSize++;
        QTableWidgetItem *Pos = new QTableWidgetItem( QString::number(P) );
        QTableWidgetItem *Cod = new QTableWidgetItem( QString::fromStdString( ActP->datos->getCodigo() ) );
        QTableWidgetItem *Dir = new QTableWidgetItem( QString::fromStdString( ActP->datos->getDireccion() ) );
        QTableWidgetItem *Col = new QTableWidgetItem( QString::fromStdString( ActP->datos->getColor() ) );
        QTableWidgetItem *Niv = new QTableWidgetItem( QString::number(ActP->datos->getNivel() ) );
        QTableWidgetItem *Hab = new QTableWidgetItem( QString::number( ActP->datos->getHabitacion() ) );
        QTableWidgetItem *Ba = new QTableWidgetItem( QString::number( ActP->datos->getBanio() ) );
        QTableWidgetItem *Par = new QTableWidgetItem( QString::number( ActP->datos->getParqueo() ) );
        QTableWidgetItem *Pre = new QTableWidgetItem( QString::number( ActP->datos->getPrecio() ) );


        ui->tableWidget_disponibles->setItem(P,0,Pos);
        ui->tableWidget_disponibles->setItem(P,1,Cod);
        ui->tableWidget_disponibles->setItem(P,2,Dir);
        ui->tableWidget_disponibles->setItem(P,3,Col);
        ui->tableWidget_disponibles->setItem(P,4,Niv);
        ui->tableWidget_disponibles->setItem(P,5,Hab);
        ui->tableWidget_disponibles->setItem(P,6,Ba);
        ui->tableWidget_disponibles->setItem(P,7,Par);
        ui->tableWidget_disponibles->setItem(P,8,Pre);

    }
}

void CFrame::MostrarPMedia()
{
    ui->tableWidget_PMedia->clear();

    ui->tableWidget_PMedia->setColumnCount(9);
    ui->tableWidget_PMedia->setRowCount( ContarPMedia() );

    ui->tableWidget_PMedia->setHorizontalHeaderLabels( QStringList()<<"Posición"<<"Código"<<"Dirección"<<"Color"<<"Niveles"<<"Habitaciones"<<"Baños"<<"Parqueos"<<"Precio");

    int P=0;
    PMediaSize =0;
    for ( ActP=ColaPMedia.PrimP ; ActP!=0 ; ActP=ActP->sigPtr, P++ ) {
        PMediaSize++;
        QTableWidgetItem *Pos = new QTableWidgetItem( QString::number(P) );
        QTableWidgetItem *Cod = new QTableWidgetItem( QString::fromStdString( ActP->datos->getCodigo() ) );
        QTableWidgetItem *Dir = new QTableWidgetItem( QString::fromStdString( ActP->datos->getDireccion() ) );
        QTableWidgetItem *Col = new QTableWidgetItem( QString::fromStdString( ActP->datos->getColor() ) );
        QTableWidgetItem *Niv = new QTableWidgetItem( QString::number(ActP->datos->getNivel() ) );
        QTableWidgetItem *Hab = new QTableWidgetItem( QString::number( ActP->datos->getHabitacion() ) );
        QTableWidgetItem *Ba = new QTableWidgetItem( QString::number( ActP->datos->getBanio() ) );
        QTableWidgetItem *Par = new QTableWidgetItem( QString::number( ActP->datos->getParqueo() ) );
        QTableWidgetItem *Pre = new QTableWidgetItem( QString::number( ActP->datos->getPrecio() ) );


        ui->tableWidget_disponibles->setItem(P,0,Pos);
        ui->tableWidget_disponibles->setItem(P,1,Cod);
        ui->tableWidget_disponibles->setItem(P,2,Dir);
        ui->tableWidget_disponibles->setItem(P,3,Col);
        ui->tableWidget_disponibles->setItem(P,4,Niv);
        ui->tableWidget_disponibles->setItem(P,5,Hab);
        ui->tableWidget_disponibles->setItem(P,6,Ba);
        ui->tableWidget_disponibles->setItem(P,7,Par);
        ui->tableWidget_disponibles->setItem(P,8,Pre);

    }
}

void CFrame::MostrarPBaja()
{
    ui->tableWidget_PBaja->clear();

    ui->tableWidget_PBaja->setColumnCount(9);
    ui->tableWidget_PBaja->setRowCount( ContarPBaja() );

    ui->tableWidget_PBaja->setHorizontalHeaderLabels( QStringList()<<"Posición"<<"Código"<<"Dirección"<<"Color"<<"Niveles"<<"Habitaciones"<<"Baños"<<"Parqueos"<<"Precio");

    int P=0;
    PBajaSize =0;
    for ( ActP=ColaBaja.PrimP ; ActP!=0 ; ActP=ActP->sigPtr, P++ ) {
        PBajaSize++;
        QTableWidgetItem *Pos = new QTableWidgetItem( QString::number(P) );
        QTableWidgetItem *Cod = new QTableWidgetItem( QString::fromStdString( ActP->datos->getCodigo() ) );
        QTableWidgetItem *Dir = new QTableWidgetItem( QString::fromStdString( ActP->datos->getDireccion() ) );
        QTableWidgetItem *Col = new QTableWidgetItem( QString::fromStdString( ActP->datos->getColor() ) );
        QTableWidgetItem *Niv = new QTableWidgetItem( QString::number(ActP->datos->getNivel() ) );
        QTableWidgetItem *Hab = new QTableWidgetItem( QString::number( ActP->datos->getHabitacion() ) );
        QTableWidgetItem *Ba = new QTableWidgetItem( QString::number( ActP->datos->getBanio() ) );
        QTableWidgetItem *Par = new QTableWidgetItem( QString::number( ActP->datos->getParqueo() ) );
        QTableWidgetItem *Pre = new QTableWidgetItem( QString::number( ActP->datos->getPrecio() ) );


        ui->tableWidget_disponibles->setItem(P,0,Pos);
        ui->tableWidget_disponibles->setItem(P,1,Cod);
        ui->tableWidget_disponibles->setItem(P,2,Dir);
        ui->tableWidget_disponibles->setItem(P,3,Col);
        ui->tableWidget_disponibles->setItem(P,4,Niv);
        ui->tableWidget_disponibles->setItem(P,5,Hab);
        ui->tableWidget_disponibles->setItem(P,6,Ba);
        ui->tableWidget_disponibles->setItem(P,7,Par);
        ui->tableWidget_disponibles->setItem(P,8,Pre);

    }
}



void CFrame::on_tabWidget_priority_type_tabBarClicked(int index)
{
    switch (index) {
    case 0:
        ui->label_Title_tabla->setText("Prioridad Alta");
        MostrarPAlta();
        break;
    case 1:
        ui->label_Title_tabla->setText("Prioridad Media");
        MostrarPMedia();
        break;
    case 2:
        ui->label_Title_tabla->setText("Prioridad Baja");
        MostrarPBaja();
        break;
    }
    ui->spinBox_Vender->setValue(0);
}


void CFrame::on_tabWidget_Listas_tabBarClicked(int index)
{
    ui->spinBox_Mover->setValue(0);
    ui->spinBox_Vender->setValue(0);
    switch (index) {
    case 0:
        ui->label_Title_tabla->setText("Casas Disponibles");

        MostrarDisponibles();
        tabPermission(1);
        break;
    case 1:

        on_tabWidget_priority_type_tabBarClicked(0);
        tabPermission(2);
        break;
    }


}


void CFrame::tabPermission (int permissionType)
{
    switch (permissionType) {
        case 1:
        ui->pBtn_Mover->setEnabled(true);
        ui->spinBox_Mover->setEnabled(true);
        ui->pBtn_Vender->setEnabled(false);
        ui->pBtn_Agregar_2->setEnabled(true);
        ui->spinBox_Vender->setEnabled(false);
        ui->label_Pos_aVender->setEnabled(false);
        ui->label_Pos_aMover->setEnabled(true);
        break;

        case 2:
        ui->pBtn_Mover->setEnabled(false);
        ui->spinBox_Mover->setEnabled(false);
        ui->pBtn_Vender->setEnabled(true);
        ui->pBtn_Agregar_2->setEnabled(false);
        ui->spinBox_Vender->setEnabled(true);
        ui->label_Pos_aVender->setEnabled(true);
        ui->label_Pos_aMover->setEnabled(false);
        break;
    }
}



void CFrame::on_spinBox_Mover_valueChanged(int arg1)
{
    int tam_validate;
    if (ui->label_Title_tabla->text() == "Casas Disponibles") {
        tam_validate=disponiblesSize;
    }else if(ui->label_Title_tabla->text()=="Prioridad Alta"){
        tam_validate=PAltaSize;
    }else if(ui->label_Title_tabla->text()=="Prioridad Media"){
        tam_validate=PMediaSize;
    }else if(ui->label_Title_tabla->text()=="Prioridad Baja"){
        tam_validate=PBajaSize;
    }

    if (arg1>tam_validate-1) {

        ui->spinBox_Mover->setValue(arg1-1);
    }

}


void CFrame::on_spinBox_Vender_valueChanged(int arg1)
{
    int tam_validate;
    if (ui->label_Title_tabla->text() == "Casas Disponibles") {
        tam_validate=disponiblesSize;
    }else if(ui->label_Title_tabla->text()=="Prioridad Alta"){
        tam_validate=PAltaSize;
    }else if(ui->label_Title_tabla->text()=="Prioridad Media"){
        tam_validate=PMediaSize;
    }else if(ui->label_Title_tabla->text()=="Prioridad Baja"){
        tam_validate=PBajaSize;
    }

    if (arg1>tam_validate-1) {

        ui->spinBox_Vender->setValue(arg1-1);
    }
}


void CFrame::on_pBtn_Mover_clicked()
{

    int index = ui->spinBox_Mover->value();

Casa* tmp = L.eliminarDeCualquier(index);
tmp->Imprimir();

if (tmp->getPrecio() < 1000000 ) {
    ColaPAlta.insertarAlFinal(tmp);
}else if((tmp->getPrecio() >= 1000000) && (tmp->getPrecio()<=2000000)){
    ColaPMedia.insertarAlFinal(tmp);
}else if(tmp->getPrecio() > 2000000){
    ColaBaja.insertarAlFinal(tmp);
}

MostrarDisponibles();

ui->spinBox_Mover->setValue(0);

}




void CFrame::on_pBtn_Vender_clicked()
{
    int index = ui->spinBox_Vender->value();

    if(ui->label_Title_tabla->text()=="Prioridad Alta"){
        Casa* tmp = ColaPAlta.eliminarDeCualquier(index);
        L.insertarAlFinal(tmp);
        MostrarPAlta();
    }else if(ui->label_Title_tabla->text()=="Prioridad Media"){
        Casa* tmp = ColaPMedia.eliminarDeCualquier(index);
        L.insertarAlFinal(tmp);
        MostrarPMedia();
    }else if(ui->label_Title_tabla->text()=="Prioridad Baja"){
        Casa* tmp = ColaBaja.eliminarDeCualquier(index);
        L.insertarAlFinal(tmp);
        MostrarPBaja();
    }

ui->spinBox_Vender->setValue(0);
}


void CFrame::on_pBtn_Agregar_2_clicked()
{
    Casa* tmp = new Casa();
    tmp->Leer();
    L.insertarAlFinal(tmp);
    MostrarDisponibles();
}

