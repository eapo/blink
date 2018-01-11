#include "blinkwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BlinkWindow w;
    w.show();

    return a.exec();
}
