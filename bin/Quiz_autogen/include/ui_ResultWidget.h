/********************************************************************************
** Form generated from reading UI file 'ResultWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTWIDGET_H
#define UI_RESULTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ResultWidget
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *ResultWidget)
    {
        if (ResultWidget->objectName().isEmpty())
            ResultWidget->setObjectName(QString::fromUtf8("ResultWidget"));
        ResultWidget->resize(683, 507);
        ResultWidget->setMinimumSize(QSize(633, 494));
        verticalLayoutWidget = new QWidget(ResultWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 10, 681, 496));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(verticalLayoutWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setMinimumSize(QSize(633, 494));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 654, 494));
        scrollAreaWidgetContents->setMinimumSize(QSize(633, 494));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(ResultWidget);

        QMetaObject::connectSlotsByName(ResultWidget);
    } // setupUi

    void retranslateUi(QWidget *ResultWidget)
    {
        ResultWidget->setWindowTitle(QCoreApplication::translate("ResultWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResultWidget: public Ui_ResultWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTWIDGET_H
