#ifndef MANDALAMAN_H
#define MANDALAMAN_H

#include <QMainWindow>

namespace Ui {
class Mandalaman;
}

class NelsonMandala;//classe du Widget central de M Seraphim
class QColorDialog;
class QColor;

class Mandalaman : public QMainWindow
{
    Q_OBJECT


public:
    explicit Mandalaman(QWidget *parent = 0);
    ~Mandalaman();

private:
    Ui::Mandalaman *ui;
    NelsonMandala * mandalaCanvas;
    int nbSlice;
    QColor color;

private slots:


    /*
    void mirrorFnct(bool);
    void clearFnct();
    void resolutionFnct(int);
    void gridFnct(bool);
    void gridTransparency(int);
    void lineWidth(int);
    void color();
    void rainbowColor();
    */
    void sliceFnct(int);

    void clearFnct();
    void saveToFile();
    QColor changeColor();
    void closeApp();
    void about();
    void on_actionQuit_triggered();
    void on_actionAbout_triggered();
    void on_actionSave_as_triggered();
    void on_colorBtn_clicked();
    void changePenWidth(int);
};

#endif // MANDALAMAN_H
