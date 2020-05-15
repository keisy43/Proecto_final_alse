#include "usuario.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    usuario w;
    w.show();

    return a.exec();
}
