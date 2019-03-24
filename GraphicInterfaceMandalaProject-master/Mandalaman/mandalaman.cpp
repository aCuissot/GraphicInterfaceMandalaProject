
#include "mandalaman.h"
#include "ui_mandalaman.h"
//#include "nelsonMandala.h"
#include "qmessagebox.h"
#include "qfiledialog.h"
#include "qcolordialog.h"
#include "QColor"

Mandalaman::Mandalaman(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Mandalaman)
{
    ui->setupUi(this);
    //mandalaCanvas = new NelsonMandala();
    color = QColor(255,255,255);
    nbSlice = 2;
    ui->rainbowColorBtn->setStyleSheet("border-image:url(:rainbowBtnImg.png)");
    connect(ui->lineWidthSlider, SIGNAL(valueChanged(int)), this, SLOT(changePenWidth(int)));
    connect(ui->clearBtn, SIGNAL(clicked()), this, SLOT(clearFnct()));
    connect(ui->sliceSlider, SIGNAL(valueChanged(int)), this, SLOT(sliceFnct(int)));
}

Mandalaman::~Mandalaman()
{
    delete ui;
}

void Mandalaman::clearFnct()
{
    ui->paintingZone->clearImage();
}

void Mandalaman::sliceFnct(int nbSlice){
    ui->paintingZone->setSliceNumber(nbSlice);
}
/*
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

QColor Mandalaman::changeColor()
{
    QColor newColor = QColorDialog::getColor(color,parentWidget());
    if ( newColor != color )
    {
        color = newColor;
    }
    return newColor;
}

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

void Mandalaman::on_colorBtn_clicked()
{
    QColor col = changeColor();
    QString qss = QString("background-color: %1").arg(col.name());
    ui->colorBtn->setStyleSheet(qss);
    ui->paintingZone->setPenColor(col);
}

void Mandalaman::changePenWidth(int w)
{
    ui->paintingZone->setPenWidth(w);
}


