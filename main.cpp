#include "Widget.h"
#include <QApplication>
#include <QTextCodec>

/*
 * Благодарность за код: https://github.com/abinghu/qt_rc
 *
*/

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings( QTextCodec::codecForName( "utf8" ) );

    QApplication app(argc, argv);

    Widget w;
    w.show();
    
    return app.exec();
}
