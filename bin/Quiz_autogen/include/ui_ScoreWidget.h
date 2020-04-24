/********************************************************************************
** Form generated from reading UI file 'ScoreWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCOREWIDGET_H
#define UI_SCOREWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScoreWidget
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *layout;
    QLabel *scoreLabel;

    void setupUi(QWidget *ScoreWidget)
    {
        if (ScoreWidget->objectName().isEmpty())
            ScoreWidget->setObjectName(QString::fromUtf8("ScoreWidget"));
        ScoreWidget->resize(631, 345);
        ScoreWidget->setMinimumSize(QSize(631, 345));
        verticalLayoutWidget = new QWidget(ScoreWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 10, 631, 331));
        layout = new QVBoxLayout(verticalLayoutWidget);
        layout->setObjectName(QString::fromUtf8("layout"));
        layout->setContentsMargins(0, 0, 0, 0);
        scoreLabel = new QLabel(verticalLayoutWidget);
        scoreLabel->setObjectName(QString::fromUtf8("scoreLabel"));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        scoreLabel->setFont(font);
        scoreLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        layout->addWidget(scoreLabel);


        retranslateUi(ScoreWidget);

        QMetaObject::connectSlotsByName(ScoreWidget);
    } // setupUi

    void retranslateUi(QWidget *ScoreWidget)
    {
        ScoreWidget->setWindowTitle(QCoreApplication::translate("ScoreWidget", "Form", nullptr));
        scoreLabel->setText(QCoreApplication::translate("ScoreWidget", "Score", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScoreWidget: public Ui_ScoreWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOREWIDGET_H
