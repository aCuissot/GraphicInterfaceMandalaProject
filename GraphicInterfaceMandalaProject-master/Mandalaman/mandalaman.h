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
    QList<QAction *> saveAsActs;


private slots:


    /*
    void mirrorFnct(bool);
    void gridFnct(bool);
    void gridTransparency(int);
    void rainbowColor();
    */

    void resolutionFnct(int);

    void sliceFnct(int);

    void clearFnct();
    void saveToFile(const QByteArray &fileFormat);
    QColor changeColor();
    void closeApp();
    void about();
    void on_actionQuit_triggered();
    void on_actionAbout_triggered();
    void on_actionSave_as_triggered();
    void on_colorBtn_clicked();
    void changePenWidth(int);
    void on_actionOpen_triggered();
};

#endif // MANDALAMAN_H
