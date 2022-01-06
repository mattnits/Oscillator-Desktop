#include "oscillator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Oscillator w;
    w.show();

    return a.exec();
}
