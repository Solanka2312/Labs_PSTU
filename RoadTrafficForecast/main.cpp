#include <QApplication>
#include <QLocale>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication::addLibraryPath("C:\\Qt\\Qt5.12.12\\5.12.12\\mingw73_32\\plugins");
    QApplication app(argc, argv);

    QLocale::setDefault(QLocale(QLocale::Russian, QLocale::Russia));

    MainWindow window;
    window.show();

    return app.exec();
}
