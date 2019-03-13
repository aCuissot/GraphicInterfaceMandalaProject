#ifndef MANDALAMAN_H
#define MANDALAMAN_H

#include <QMainWindow>

namespace Ui {
class Mandalaman;
}

class NelsonMandala;//classe du Widget central de M Seraphim

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

private slots:
/*
    void sliceFnct(int);
    void mirrorFnct(bool);
    void clearFnct();
    void resolutionFnct(int);
    void gridFnct(bool);
    void gridTransparency(int);
    void lineWidth(int);
    void color();
    void rainbowColor();
    */
    void saveToFile();

    void closeApp();
    void about();
    void on_actionQuit_triggered();
    void on_actionAbout_triggered();
    void on_actionSave_as_triggered();
};

#endif // MANDALAMAN_H
