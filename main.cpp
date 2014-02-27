#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>

/*
 * Генератора кода взят отсюда: https://github.com/abinghu/qt_rc
 *
*/

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings( QTextCodec::codecForName( "utf8" ) );

    QApplication app(argc, argv);

    MainWindow w;
    w.show();
    
    return app.exec();
}
