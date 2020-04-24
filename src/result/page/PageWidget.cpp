/**
 * @file PageWidget.hpp
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
 * The PageWidget source file implements the PageWidget class and sets up it's children. It's visual config is auto generated
 *  and defined in ui_PageWidget.h and PageWidget.ui. The declaration of PageWidget.cpp is in PageWidget.hpp.
 * 
 * Each PageWidget object will display the question, the correct answer, and the entered answer, the entered answer will
 *  be colored as either red or green depending on if it was correct or not.
 * 
 * @see PageWidget.ui
 * @see ui_PageWidget.h
 * @see PageWidget.hpp
 */

#include "PageWidget.hpp"   // PageWidget
#include "ui_PageWidget.h"  // Ui::PageWidget
#include "../../Style.hpp"  // Style::LoadWidgetStyle

PageWidget::PageWidget(std::size_t index, QString const& question, QString const& correct, QString const& ans, QWidget* parent)
    :   QWidget(parent),
        m_UI(std::make_unique<Ui::PageWidget>())
{
    m_UI->setupUi(this);
    Style::LoadWidgetStyle(*this, "../resources/styles.qss");

    m_UI->questionLabel->setText(QString("%1: %2").arg(QString::number(++index), question));

    m_UI->ansLabel->setText(QString("Your answer: %1").arg(ans));
    m_UI->ansLabel->setStyleSheet(ans == correct ? "color: green;" : "color: red;");
    m_UI->correctLabel->setText(QString("Correct answer: %1").arg(correct));
}

/**
 * Destructor that destroys the page widget
 */
PageWidget::~PageWidget() {}