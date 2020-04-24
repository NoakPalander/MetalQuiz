/********************************************************************************
** Form generated from reading UI file 'QuizWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUIZWIDGET_H
#define UI_QUIZWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuizWidget
{
public:
    QGroupBox *qna;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *questionLabel;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *optionsLayout;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *nextBtn;

    void setupUi(QWidget *QuizWidget)
    {
        if (QuizWidget->objectName().isEmpty())
            QuizWidget->setObjectName(QString::fromUtf8("QuizWidget"));
        QuizWidget->resize(680, 291);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QuizWidget->sizePolicy().hasHeightForWidth());
        QuizWidget->setSizePolicy(sizePolicy);
        QuizWidget->setMinimumSize(QSize(680, 291));
        QFont font;
        font.setPointSize(11);
        QuizWidget->setFont(font);
#if QT_CONFIG(accessibility)
        QuizWidget->setAccessibleName(QString::fromUtf8("quizWidget"));
#endif // QT_CONFIG(accessibility)
        QuizWidget->setStyleSheet(QString::fromUtf8(""));
        qna = new QGroupBox(QuizWidget);
        qna->setObjectName(QString::fromUtf8("qna"));
        qna->setGeometry(QRect(0, 0, 681, 291));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(qna->sizePolicy().hasHeightForWidth());
        qna->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setUnderline(false);
        font1.setWeight(50);
        font1.setStrikeOut(false);
        font1.setKerning(true);
        qna->setFont(font1);
        qna->setFlat(false);
        verticalLayoutWidget = new QWidget(qna);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 30, 661, 248));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        questionLabel = new QLabel(verticalLayoutWidget);
        questionLabel->setObjectName(QString::fromUtf8("questionLabel"));
        sizePolicy.setHeightForWidth(questionLabel->sizePolicy().hasHeightForWidth());
        questionLabel->setSizePolicy(sizePolicy);
        questionLabel->setMinimumSize(QSize(591, 0));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        questionLabel->setFont(font2);
        questionLabel->setTextFormat(Qt::PlainText);
        questionLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        questionLabel->setWordWrap(true);

        verticalLayout->addWidget(questionLabel);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        optionsLayout = new QHBoxLayout();
        optionsLayout->setObjectName(QString::fromUtf8("optionsLayout"));

        verticalLayout->addLayout(optionsLayout);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        nextBtn = new QPushButton(verticalLayoutWidget);
        nextBtn->setObjectName(QString::fromUtf8("nextBtn"));

        horizontalLayout->addWidget(nextBtn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(QuizWidget);

        QMetaObject::connectSlotsByName(QuizWidget);
    } // setupUi

    void retranslateUi(QWidget *QuizWidget)
    {
        QuizWidget->setWindowTitle(QCoreApplication::translate("QuizWidget", "Form", nullptr));
#if QT_CONFIG(accessibility)
        qna->setAccessibleName(QCoreApplication::translate("QuizWidget", "quizWidget", nullptr));
#endif // QT_CONFIG(accessibility)
        qna->setTitle(QCoreApplication::translate("QuizWidget", " Death Metal Quiz! Try to get all the questions right!", nullptr));
#if QT_CONFIG(accessibility)
        questionLabel->setAccessibleName(QCoreApplication::translate("QuizWidget", "question", nullptr));
#endif // QT_CONFIG(accessibility)
        questionLabel->setText(QCoreApplication::translate("QuizWidget", "Question", nullptr));
        nextBtn->setText(QCoreApplication::translate("QuizWidget", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuizWidget: public Ui_QuizWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUIZWIDGET_H
