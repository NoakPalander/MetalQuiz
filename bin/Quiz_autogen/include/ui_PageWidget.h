/********************************************************************************
** Form generated from reading UI file 'PageWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGEWIDGET_H
#define UI_PAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PageWidget
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *questionLabel;
    QSpacerItem *verticalSpacer_2;
    QLabel *ansLabel;
    QLabel *correctLabel;
    QSpacerItem *verticalSpacer_3;
    QFrame *line;

    void setupUi(QWidget *PageWidget)
    {
        if (PageWidget->objectName().isEmpty())
            PageWidget->setObjectName(QString::fromUtf8("PageWidget"));
        PageWidget->resize(631, 172);
        PageWidget->setMinimumSize(QSize(631, 172));
        verticalLayoutWidget = new QWidget(PageWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(6, 10, 621, 161));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        questionLabel = new QLabel(verticalLayoutWidget);
        questionLabel->setObjectName(QString::fromUtf8("questionLabel"));
        questionLabel->setMinimumSize(QSize(610, 45));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        questionLabel->setFont(font);
        questionLabel->setTextFormat(Qt::PlainText);
        questionLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        questionLabel->setWordWrap(true);

        verticalLayout->addWidget(questionLabel);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        ansLabel = new QLabel(verticalLayoutWidget);
        ansLabel->setObjectName(QString::fromUtf8("ansLabel"));
        QFont font1;
        font1.setPointSize(12);
        ansLabel->setFont(font1);
        ansLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(ansLabel);

        correctLabel = new QLabel(verticalLayoutWidget);
        correctLabel->setObjectName(QString::fromUtf8("correctLabel"));
        correctLabel->setFont(font1);
        correctLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(correctLabel);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        line = new QFrame(verticalLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        retranslateUi(PageWidget);

        QMetaObject::connectSlotsByName(PageWidget);
    } // setupUi

    void retranslateUi(QWidget *PageWidget)
    {
        PageWidget->setWindowTitle(QCoreApplication::translate("PageWidget", "Form", nullptr));
        questionLabel->setText(QCoreApplication::translate("PageWidget", "Question", nullptr));
        ansLabel->setText(QCoreApplication::translate("PageWidget", "You answer", nullptr));
        correctLabel->setText(QCoreApplication::translate("PageWidget", "Correct answer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PageWidget: public Ui_PageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGEWIDGET_H
