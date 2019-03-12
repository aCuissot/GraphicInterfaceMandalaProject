#include "mandalaman.h"
#include "ui_mandalaman.h"
//#include "nelsonMandala.h"


Mandalaman::Mandalaman(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Mandalaman)
{
    ui->setupUi(this);
}

Mandalaman::~Mandalaman()
{
    delete ui;
}

void Mandalaman::sliceFnct(int nbSlice){
    mandalaCanvas.setSliceNumber(nbSlice);
}

void Mandalaman::mirrorFnct(bool isMirrorActivated){
    mandalaCanvas.setMirror(isMirrorActivated);
}

void Mandalaman::clearFnct(){
    mandalaCanvas.clear();
}

void Mandalaman::resolutionFnct(int resNber){
    switch(resNber){
        case 1:
            mandalaCanvas.setResolution(500,500);
            break;
        case 2:
            mandalaCanvas.setResolution(400,400);
            break;
        default:
            mandalaCanvas.setResolution(300,300);
    }
}

void Mandalaman::closeApp(){
    QMessageBox::StandardButton button;
    button = QMessageBox::question(this,
                                   "You want to quit...",
                                   "Are you sure that you want to quit"
                                   " this great application?",
                                   QMessageBox::Yes|QMessageBox::No,
                                   QMessageBox::No );
    if ( button == QMessageBox::Yes ) {
      close();
    }
}

void Mandalaman::about()
{
    QMessageBox::StandardButton button;
    button = QMessageBox::information(this,
                                   "Calculatrice",
                                   "Anneau Nimes"
                                   "Copyright JOOJ",
                                   QMessageBox::Yes );
}
