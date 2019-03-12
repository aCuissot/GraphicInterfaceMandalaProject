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


private slots:
    void sliceFnct(int);
    void mirrorFnct(bool);
    void clearFnct();
    void resolutionFnct(int);
    void gridFnct(bool);
    void gridTransparency(int);
    void lineWidth(int);
    void color();
    void rainbowColor();
    void closeApp();
};

#endif // MANDALAMAN_H
