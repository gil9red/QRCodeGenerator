#include "Widget.h"
#include "ui_Widget.h"

#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMouseEvent>
#include <QScrollArea>
#include <QImageWriter>
#include <QScrollBar>

#include <QDebug>

/// PUBLIC
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    successfulEncoding(false)
{
    ui->setupUi(this);

    setWindowTitle( nameProgram );

    ui->scrollArea->installEventFilter( this );
    ui->splitter->setSizes( QList < int > () << maximumHeight() );
    ui->splitter_2->setSizes( QList < int > () << maximumHeight() );

    ui->sBoxScale->setValue(4);

    connect( ui->pButtonSave, SIGNAL( clicked() ), SLOT( save() ) );
    connect( ui->plainTextEdit, SIGNAL( textChanged() ), SLOT( updateQRImage() ) );
    connect( ui->sBoxScale, SIGNAL( valueChanged(int) ), SLOT( setScale(int) ) );

    updateQRImage();
}

Widget::~Widget()
{
    delete ui;
}

/// PRIVATE SLOTS
void Widget::updateQRImage()
{
    ui->labelSizeText->setText( QString::number( ui->plainTextEdit->toPlainText().size() ) );

    int level_index = 1;
    int version_index = 0;
    bool bExtent = true;
    int mask_index = -1;

    QString encode_string = ui->plainTextEdit->toPlainText();

    successfulEncoding = qrEncode.EncodeData(level_index,
                                             version_index,
                                             bExtent,
                                             mask_index,
                                             encode_string.toAscii().data());

    if (!successfulEncoding)
	{
		ui->image_label->clear();
        ui->image_label->setText( "Изображение..." );
        ui->labelSize->clear();
        ui->pButtonSave->setEnabled( successfulEncoding );
		return;
	}

    int qrImageSize = qrEncode.m_nSymbleSize;

    // Создаем двумерный образ кода
    encodeImageSize = qrImageSize + ( QR_MARGIN * 2 );
    QImage encode_image( encodeImageSize, encodeImageSize, QImage::Format_Mono );
    encode_image.fill( 1 );

    // Создать двумерный образ кода
    for ( int i = 0; i < qrImageSize; i++ )
        for ( int j = 0; j < qrImageSize; j++ )
            if ( qrEncode.m_byModuleData[i][j] )
                encode_image.setPixel( i + QR_MARGIN, j + QR_MARGIN, 0 );

    ui->image_label->setPixmap( QPixmap::fromImage( encode_image ) );

    // Размер дисплея двумерные характеристики код
    setScale(0);

    ui->pButtonSave->setEnabled( successfulEncoding );
}
void Widget::setScale( int )
{
    if ( successfulEncoding )
	{
        int scale = ui->sBoxScale->value();
        int scale_size = encodeImageSize*scale;

        const QPixmap & scale_image = ui->image_label->pixmap()->scaled( scale_size, scale_size );
        ui->image_label->setPixmap( scale_image );

        const QString & size_info = QString( "%1x%2" ).arg( scale_size ).arg( scale_size );
        ui->labelSize->setText( size_info );
	}
}
void Widget::save()
{
    QString suffix;
    foreach ( const QByteArray & format , QImageWriter::supportedImageFormats() )
        suffix += QString( "%1 ( *.%2 )\n" )
                .arg( QString( format ).toUpper() )
                .arg( QString( format ) );

    const QString & path = QFileDialog::getSaveFileName( this,
                                                         tr("save file"),
                                                         QString( "qr_code" ),
                                                         suffix );
    if ( path.isNull() )
        return;

    ui->image_label->pixmap()->save( path );
}

/// PROTECTED
bool Widget::eventFilter( QObject * object, QEvent * event )
{
    QScrollArea * scrollArea = ui->scrollArea;

    if ( object == scrollArea )
    {
        if ( event->type() == QEvent::MouseButtonPress )
        {
            QMouseEvent * mouseEvent = static_cast < QMouseEvent * > ( event );
            if ( mouseEvent->button() == Qt::LeftButton )
            {
                lastPos = mouseEvent->pos();

                if( scrollArea->horizontalScrollBar()->isVisible()
                        || scrollArea->verticalScrollBar()->isVisible() )
                    scrollArea->setCursor( Qt::ClosedHandCursor );
                else
                    scrollArea->setCursor( Qt::ArrowCursor );
            }

        }else if ( event->type() == QEvent::MouseMove )
        {
            QMouseEvent *mouseEvent = static_cast < QMouseEvent * > ( event );

            if ( mouseEvent->buttons() == Qt::LeftButton )
            {
                lastPos -= mouseEvent->pos();

                int hValue = scrollArea->horizontalScrollBar()->value();
                int vValue = scrollArea->verticalScrollBar()->value();

                scrollArea->horizontalScrollBar()->setValue( lastPos.x() + hValue );
                scrollArea->verticalScrollBar()->setValue( lastPos.y() + vValue );

                lastPos = mouseEvent->pos();
            }

        }else if ( event->type() == QEvent::MouseButtonRelease )
            scrollArea->setCursor( Qt::ArrowCursor );
    }

    return QWidget::eventFilter(object, event);
}
