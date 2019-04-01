
#include "mandalaman.h"
#include "ui_mandalaman.h"
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


    connect(ui->lineWidthSlider, SIGNAL(valueChanged(int)), this, SLOT(changePenWidth(int)));
    connect(ui->clearBtn, SIGNAL(clicked()), this, SLOT(clearFnct()));
    connect(ui->sliceSlider, SIGNAL(valueChanged(int)), this, SLOT(sliceFnct(int)));
    connect(ui->resolutionDropDownList, SIGNAL(currentIndexChanged(int)), this, SLOT(resolutionFnct(int)));
    connect(ui->rainbowColorBtn, SIGNAL(clicked()), this, SLOT (rainbowColor()));
    connect(ui->mirrorCheckBox, SIGNAL(clicked()), this, SLOT(mirrorFnct()));
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

void Mandalaman::resolutionFnct(int resNber){
    switch(resNber){
        case 1:
            ui->paintingZone->resize(QSize(400,400));
            break;
        case 2:
            ui->paintingZone->resize(QSize(300,300));
            break;
        default:
            ui->paintingZone->resize(QSize(500,500));
    }
}

void Mandalaman::rainbowColor(){
    ui->paintingZone->setRainbow();
}



void Mandalaman::mirrorFnct(){
    ui->paintingZone->setMirror();
}
/*
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

void Mandalaman::saveToFile(const QByteArray &fileFormat)
{
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save Mandala"), "",
        tr("JPG image (*.jpg);;PNG image (*.png);;All Files (*)"));

    ui->paintingZone->saveImage(fileName);

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
                                   "Ceci est une application de Mandala certifiée"
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
    QAction *action = qobject_cast<QAction *>(sender());
    QByteArray fileFormat = action->data().toByteArray();
    saveToFile(fileFormat);
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



void Mandalaman::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                               tr("Open File"), QDir::currentPath());
    if (!fileName.isEmpty())
        ui->paintingZone->openImage(fileName);
}
