/**
 * @file MainWindow.hpp
 * @author Noak Palander <noak.palander@protonmail.com>
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
 * The MainWindow file implements the MainWindow class functions along side the auto generated ui_MainWindow.h
 * @see MainWindow.hpp
 * @see ui_MainWindow.h
 */

#include "MainWindow.hpp"               // MainWindow
#include "./ui_MainWindow.h"            // Ui::MainWindow
#include "../Question.hpp"              // Question
#include "../quiz/QuizWidget.hpp"       // QuizWidget
#include "../result/ResultWidget.hpp"   // ResultWidget
#include "../Style.hpp"                 // Style::LoadStyle
#include <fstream>                      // std::ifstream
#include <sstream>                      // std::stringstream
#include <iostream>                     // std::cout

/**
 * Constructor that constructs the mainwindow and sets it's children
 * 
 * @param parent The parent object of the class, default initialized to nullptr
 */
MainWindow::MainWindow(QWidget* parent)
    :   QMainWindow(parent), 
        m_UI(std::make_unique<Ui::MainWindow>())
{
    m_UI->setupUi(this);
    Style::LoadWidgetStyle(*this, "../resources/styles.qss");

    // Creates a quizwidget and sets the mainwindow's content to be that frame
    QuizWidget* quiz = new QuizWidget(this);
    this->setCentralWidget(quiz);

    // Connect the QWidget::Finished(quiz) signal to a lambda-slot, which
    // displays a result page
    connect(quiz, &QuizWidget::Finished, this, [this, quiz]() {
        // replace with the result page!
        this->setCentralWidget(new ResultWidget(*quiz, this));
    });
}

/**
 * Destructor that destroys the mainwindow
 */
MainWindow::~MainWindow() {}