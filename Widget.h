#ifndef Widget_H
#define Widget_H

#include <QWidget>
#include <QEvent>

#include "QRCodeGenerator.h"

namespace Ui {
class Widget;
}

const static QString nameProgram = "QRCode Generator";

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private slots:
    void updateQRImage();
    void setScale(int);
    void save();

private:
    Ui::Widget *ui;
    CQR_Encode qrEncode;
    bool successfulEncoding;
    int encodeImageSize;
    QPoint lastPos;

protected:
    bool eventFilter( QObject * object, QEvent * event );
};

#endif // Widget_H
