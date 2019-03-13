#include "mandalaman.h"
#include "ui_mandalaman.h"
//#include "nelsonMandala.h"
#include "qmessagebox.h"
#include "qfiledialog.h"

class NelsonMandala;

Mandalaman::Mandalaman(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Mandalaman)
{
    ui->setupUi(this);
    //mandalaCanvas = new NelsonMandala();
    nbSlice = 2;
}

Mandalaman::~Mandalaman()
{
    delete ui;
}
/*
void Mandalaman::sliceFnct(int nbSlice){
    mandalaCanvas->setSliceNumber(nbSlice);
}

void Mandalaman::mirrorFnct(bool isMirrorActivated){
    mandalaCanvas->setMirror(isMirrorActivated);
}

void Mandalaman::clearFnct(){
    mandalaCanvas->clear();
}

void Mandalaman::resolutionFnct(int resNber){
    switch(resNber){
        case 1:
            mandalaCanvas->setResolution(500,500);
            break;
        case 2:
            mandalaCanvas->setResolution(400,400);
            break;
        default:
            mandalaCanvas->setResolution(300,300);
    }
}

void Mandalaman::gridFnct(bool displayGrid){
    mandalaCanvas->displayGrid(nbSlice, displayGrid);
}

void Mandalaman::gridTransparency(int transparency){
    mandalaCanvas->setGridTransparency(transparency);
}

void Mandalaman::lineWidth(int width){
    mandalaCanvas->setLineWidth(width);
}

void Mandalaman::color(){

}

void Mandalaman::rainbowColor(){

}

*/
void Mandalaman::saveToFile()
{
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save Mandala"), "",
        tr("JPG image (*.jpg);;PNG image (*.png);;All Files (*)"));
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
                                   "Mandala Maker",
                                   "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
                                   "Copyright",
                                   QMessageBox::Yes );
}


void Mandalaman::on_actionQuit_triggered()
{
    closeApp();
}

void Mandalaman::on_actionAbout_triggered()
{
    about();
}

void Mandalaman::on_actionSave_as_triggered()
{
    saveToFile();
}
