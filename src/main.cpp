#include "hvildtomato.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    HvildTomato w;
    w.show();

    return app.exec();
}

