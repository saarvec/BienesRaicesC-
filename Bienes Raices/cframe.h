#ifndef CFRAME_H
#define CFRAME_H

#include <QMainWindow>
#include <Lista.h>
#include <Cola.h>


QT_BEGIN_NAMESPACE
namespace Ui { class CFrame; }
QT_END_NAMESPACE


class CFrame : public QMainWindow
{
    Q_OBJECT

public:
    CFrame(QWidget *parent = nullptr);
    ~CFrame();
    void Predefinido();
    int ContarDisponibles();
    int ContarPAlta();
    int ContarPMedia();
    int ContarPBaja();
    void MostrarDisponibles();
    void MostrarPAlta();
    void MostrarPMedia();
    void MostrarPBaja();
    void tabPermission(int permissionType);
    int disponiblesSize;
    int PAltaSize;
    int PMediaSize;
    int PBajaSize;


private slots:
    void on_tabWidget_priority_type_tabBarClicked(int index);

    void on_tabWidget_Listas_tabBarClicked(int index);

    void on_spinBox_Mover_valueChanged(int arg1);

    void on_spinBox_Vender_valueChanged(int arg1);

    void on_pBtn_Mover_clicked();

    void on_pBtn_Vender_clicked();

    void on_pBtn_Agregar_2_clicked();

private:
    Ui::CFrame *ui;
    Lista <Casa*> L;
    Cola <Casa*> ColaPAlta ,ColaPMedia,ColaBaja ;
    Nodo <Casa*> *ActP;


};
#endif // CFRAME_H
