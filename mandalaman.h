#ifndef MANDALAMAN_H
#define MANDALAMAN_H

#include <QDialog>

namespace Ui {
class Mandalaman;
}

class Mandalaman : public QDialog
{
    Q_OBJECT

public:
    explicit Mandalaman(QWidget *parent = 0);
    ~Mandalaman();

private:
    Ui::Mandalaman *ui;
};

#endif // MANDALAMAN_H
