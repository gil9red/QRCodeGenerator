/********************************************************************************
** Form generated from reading UI file 'Widget.ui'
**
** Created: Sat 7. Dec 01:08:15 2013
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QSplitter>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_3;
    QSplitter *splitter_2;
    QSplitter *splitter;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_7;
    QLabel *image_label;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QFormLayout *formLayout;
    QLabel *label_3;
    QSpinBox *sBoxScale;
    QLabel *label;
    QLabel *labelSize;
    QLabel *label_5;
    QLabel *labelSizeText;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pButtonSave;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(476, 319);
        verticalLayout_3 = new QVBoxLayout(Widget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        splitter_2 = new QSplitter(Widget);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        splitter_2->setHandleWidth(10);
        splitter_2->setChildrenCollapsible(false);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(10);
        splitter->setChildrenCollapsible(false);
        scrollArea = new QScrollArea(splitter);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 219, 121));
        verticalLayout_7 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        image_label = new QLabel(scrollAreaWidgetContents);
        image_label->setObjectName(QString::fromUtf8("image_label"));
        image_label->setFrameShape(QFrame::StyledPanel);
        image_label->setAlignment(Qt::AlignCenter);
        image_label->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout_7->addWidget(image_label);

        scrollArea->setWidget(scrollAreaWidgetContents);
        splitter->addWidget(scrollArea);
        widget = new QWidget(splitter);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        sBoxScale = new QSpinBox(widget);
        sBoxScale->setObjectName(QString::fromUtf8("sBoxScale"));
        sBoxScale->setMinimum(1);
        sBoxScale->setMaximum(20);

        formLayout->setWidget(0, QFormLayout::FieldRole, sBoxScale);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        labelSize = new QLabel(widget);
        labelSize->setObjectName(QString::fromUtf8("labelSize"));

        formLayout->setWidget(1, QFormLayout::FieldRole, labelSize);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        labelSizeText = new QLabel(widget);
        labelSizeText->setObjectName(QString::fromUtf8("labelSizeText"));

        formLayout->setWidget(2, QFormLayout::FieldRole, labelSizeText);


        verticalLayout->addLayout(formLayout);

        verticalSpacer_2 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        pButtonSave = new QPushButton(widget);
        pButtonSave->setObjectName(QString::fromUtf8("pButtonSave"));

        verticalLayout->addWidget(pButtonSave);

        splitter->addWidget(widget);
        splitter_2->addWidget(splitter);
        widget1 = new QWidget(splitter_2);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        plainTextEdit = new QPlainTextEdit(widget1);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        verticalLayout_2->addWidget(plainTextEdit);

        splitter_2->addWidget(widget1);

        verticalLayout_3->addWidget(splitter_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        image_label->setText(QApplication::translate("Widget", "\320\230\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265...", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Widget", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261: ", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "\320\240\320\260\320\267\320\274\320\265\321\200:", 0, QApplication::UnicodeUTF8));
        labelSize->setText(QString());
        label_5->setText(QApplication::translate("Widget", "\320\241\320\270\320\274\320\262\320\276\320\273\320\276\320\262:", 0, QApplication::UnicodeUTF8));
        labelSizeText->setText(QString());
        pButtonSave->setText(QApplication::translate("Widget", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272...", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget", "\320\242\320\265\320\272\321\201\321\202:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
