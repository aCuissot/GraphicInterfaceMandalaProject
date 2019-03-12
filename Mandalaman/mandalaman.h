#ifndef MANDALAMAN_H
#define MANDALAMAN_H

#include <QMainWindow>

namespace Ui {
class Mandalaman;
}

class Mandalaman : public QMainWindow
{
    Q_OBJECT

public:
    explicit Mandalaman(QWidget *parent = 0);
    ~Mandalaman();

private:
    Ui::Mandalaman *ui;
};

#endif // MANDALAMAN_H
