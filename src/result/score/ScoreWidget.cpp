/**
 * @file ScoreWidget.cpp
 * @author Noak Palander noak.palander@protonmail.com
 * @version 1.0
 * 
 * @section LICENSE
 * 
 * Copyright 2020 Noak Palander
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), 
 *  to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 *  and/or sell copies of the Software, 
 *  and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
 *  TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * @section DESCRIPTION
 * 
 * The ScoreWidget source file implements the ScoreWidget class and sets up it's children. It's visual config is auto generated
 *  and defined in ui_ScoreWidget.hpp and ScoreWidget.ui. The declaration of ScoreWidget.cpp is in ScoreWidget.hpp. 
 * 
 * The ScoreWidget object will display the total percentage of the questions answered correctly, and an image if the rate is above
 *  a certain threshold.
 * 
 * @see ui_ScoreWidget.h
 * @see ScoreWidget.ui
 * @see ScoreWidget.hpp
 */

#include "ScoreWidget.hpp"      // ScoreWidget
#include "./ui_ScoreWidget.h"     // Ui::ScoreWidget
#include <QLabel>               // QLabel
#include <QPixmap>              // QPixmap
#include <sstream>              // std::stringstream
#include <iomanip>              // set::setprecision
#include "../../Style.hpp"      // Style::LoadWidgetStyle

/**
 * Constructor that constructs the score widget and sets it's children
 * 
 * @param score The score for the slide
 * @param length The amount of slides (questions)
 * @param parent The parent object of the class, default initialized to nullptr
 */
ScoreWidget::ScoreWidget(std::size_t score, std::size_t length, QWidget* parent) 
    :   QWidget(parent),
        m_UI(std::make_unique<Ui::ScoreWidget>())
{
    m_UI->setupUi(this);
    Style::LoadWidgetStyle(*this, "../resources/styles.qss");

    // Can only calculate score if length is greater than 0 (else: division by 0)
    if (length > 0) {
        // Sets the score labels text
        std::stringstream ss;
        ss << "You got " << score << "/" << length << " (" << std::setprecision(3) << 
            static_cast<float>(score) / static_cast<float>(length) * 100 << "%) right!";
        
        this->findChild<QLabel*>("scoreLabel")->setText(QString::fromStdString(ss.str()));
    }
    else {
        this->findChild<QLabel*>("scoreLabel")->setText("??");
    }
    
    // Sets the path to the good image if the score is above or equal to 50%, else set the bad path
    QString path = (static_cast<float>(score) / static_cast<float>(length) >= 0.5 ? 
        "../resources/good.png" : "../resources/bad.png");

    // Loads a centered image
    QPixmap image(path);
    QLabel* label = new QLabel(this);
    label->setAlignment(Qt::AlignHCenter);
    label->setPixmap(image);
    m_UI->layout->addWidget(label);

    // Creates a horizontal line
    QFrame* line = new QFrame(this);
    line->setObjectName(QString::fromUtf8("line"));
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    m_UI->layout->addWidget(line);
}

/**
 * Destructor that destroys the score widget
 */
ScoreWidget::~ScoreWidget() {}