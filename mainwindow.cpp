/*************************************************************************
**
** Copyright (C) 2014-2014 by Ilya Petrash
** All rights reserved.
** Contact: gil9red@gmail.com, ip1992@inbox.ru
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the
** Free Software Foundation, Inc.,
** 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
**
**************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMouseEvent>
#include <QScrollArea>
#include <QImageWriter>
#include <QScrollBar>
#include <QSettings>
#include <QApplication>

#include <QDebug>

const QString getIniPath()
{
    const static QString iniPath( qApp->applicationDirPath() + "/settings.ini" );
    return iniPath;
}
QString saveFormats()
{
    static QString suffix;
    foreach ( const QByteArray & format , QImageWriter::supportedImageFormats() )
        suffix += QString( "%1 ( *.%2 )\n" )
                .arg( QString( format ).toUpper() )
                .arg( QString( format ) );

    return suffix;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    successfulEncoding(false)
{
    ui->setupUi(this);
    ui->scrollArea->installEventFilter( this );

    QSettings ini( getIniPath(), QSettings::IniFormat );
    ui->splitter_2->restoreState( ini.value( ui->splitter_2->objectName() ).toByteArray() );
    ui->splitter->restoreState( ini.value( ui->splitter->objectName() ).toByteArray() );
    ui->sBoxScale->setValue( ini.value( ui->sBoxScale->objectName(), 4 ).toInt() );
    restoreState( ini.value( "State" ).toByteArray() );
    restoreGeometry( ini.value( "Geometry" ).toByteArray() );

    setScale( ui->sBoxScale->value() );
    updateQRImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateQRImage()
{
    int sizeText = ui->pTextEditQRText->toPlainText().size();
    ui->labelSizeText->setText( QString::number( sizeText ) );

    int levelIndex = 1;
    int versionIndex = 0;
    bool bExtent = true;
    int maskIndex = -1;
    QString encodeString = ui->pTextEditQRText->toPlainText();

    successfulEncoding = qrEncode.EncodeData( levelIndex, versionIndex, bExtent, maskIndex, encodeString.toUtf8().data() );
    if ( !successfulEncoding )
    {
        ui->image_label->clear();
        ui->image_label->setText( tr("QR Code...") );
        ui->labelSize->clear();
        ui->pButtonSave->setEnabled( successfulEncoding );
        return;
    }

    int qrImageSize = qrEncode.m_nSymbleSize;

    // Создаем двумерный образ кода
    encodeImageSize = qrImageSize + ( QR_MARGIN * 2 );
    QImage encodeImage( encodeImageSize, encodeImageSize, QImage::Format_Mono );
    encodeImage.fill( 1 );

    // Создать двумерный образ кода
    for ( int i = 0; i < qrImageSize; i++ )
        for ( int j = 0; j < qrImageSize; j++ )
            if ( qrEncode.m_byModuleData[i][j] )
                encodeImage.setPixel( i + QR_MARGIN, j + QR_MARGIN, 0 );

    ui->image_label->setPixmap( QPixmap::fromImage( encodeImage ) );

    setScale(ui->sBoxScale->value());
    ui->pButtonSave->setEnabled( successfulEncoding );
}
void MainWindow::setScale(int scale)
{
    if ( successfulEncoding )
    {
        int scale_size = encodeImageSize * scale;

        const QPixmap & scale_image = ui->image_label->pixmap()->scaled( scale_size, scale_size );
        ui->image_label->setPixmap( scale_image );

        const QString & size_info = QString( "%1x%2" ).arg( scale_size ).arg( scale_size );
        ui->labelSize->setText( size_info );
    }
}

void MainWindow::on_pButtonSave_clicked()
{
    const QString & path = QFileDialog::getSaveFileName( this, QString::null, "qrcode", saveFormats() );
    if ( path.isNull() )
        return;

    ui->image_label->pixmap()->save( path );
}
void MainWindow::on_sBoxScale_valueChanged(int arg1)
{
    setScale( arg1 );
}
void MainWindow::on_pTextEditQRText_textChanged()
{
    updateQRImage();
}
void MainWindow::on_pButtonQuit_clicked()
{
    close();
}

void MainWindow::closeEvent(QCloseEvent *)
{
    QSettings ini( getIniPath(), QSettings::IniFormat );
    ini.setValue( ui->splitter->objectName(), ui->splitter->saveState() );
    ini.setValue( ui->splitter_2->objectName(), ui->splitter_2->saveState() );
    ini.setValue( ui->sBoxScale->objectName(), ui->sBoxScale->value() );
    ini.setValue( "State", saveState() );
    ini.setValue( "Geometry", saveGeometry() );

    qApp->quit();
}
bool MainWindow::eventFilter( QObject * object, QEvent * event )
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
