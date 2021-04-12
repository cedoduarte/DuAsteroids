/**
 * @author: Carlos Enrique Duarte Ortiz <carlosduarte.1@hotmail.com>
 */

#include "DuAsteroidsMainWidget.h"
#include <QApplication>
#include <ctime>

using namespace DuarteCorporation;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qsrand(time(nullptr));
    a.setStyle("fusion");
    DuAsteroidsMainWidget w;
    w.showMaximized();
    return a.exec();
}
