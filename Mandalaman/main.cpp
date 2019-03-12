#include "mandalaman.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mandalaman w;
    w.show();

    return a.exec();
}
