/**
 * @file QuizWidget.hpp
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
 * The QuizWidget file declares the QuizWidget class and sets up it's children. It's visual config is auto generated
 *  and defined in ui_QuizWidget.h and QuizWidget.ui. The implementation of QuizWidget.hpp is in QuizWidget.cpp.
 * 
 * The QuizWidget object will display each slide, these slide contains a label of the question, radiobuttons for the options,
 *  and a next button, to advance the quiz.
 * 
 * @see QuizWidget.ui
 * @see ui_QuizWidget.h
 * @see QuizWidget.cpp
 */

#pragma once                    // Include Guard

#include "../Question.hpp"      // Question
#include <QWidget>              // QWidget
#include <memory>               // std::unique_ptr
#include <tuple>                // std::tuple
#include <vector>               // std::vector
#include <utility>              // std::pair

// Forward declares Ui::QuizWidget
namespace Ui { 
    class QuizWidget; 
}

/**
 * @class QuizWidget
 * @brief Implements the page widget and that sets up the child widgets.
 * @extends QWidget
 * 
 * QuizWidget is a of child of the MainWindow, it's initialized during the start of the application.
 * 
 * @see QuizWidget.ui
 * @see ui_QuizWidget.h
 * @see QuizWidget.cpp
 */
class QuizWidget : public QWidget {
public:
   /**
     * Constructor that constructs the quiz widget and sets it's slides
     * 
     * @param parent The parent QWidget-object of the class, default initialized to nullptr
     */
    explicit QuizWidget(QWidget* parent = nullptr);
    
    /**
     * Destructor that destroys the quiz widget
     */
    ~QuizWidget();
    
    /**
     * Gets the results of the slide i.e the user's entered option
     * 
     * @param index The question index
     * @returns A std::tuple containing the question, answer, and selected option for the passed index
     */
    std::tuple<QString, QString, QString> GetResults(std::size_t index) const;

    /**
     * Gets the total score calculated by all slides 
     * 
     * @returns An std::size_t containing score
     */
    std::size_t GetScore() const;

    /**
     * Gets the number of questions in the quiz
     * 
     * @returns An std::size_t containing the number of quiz-slides
     */
    std::size_t GetLength() const;

    /**
     * Sends a signal that the quiz is finished
     */
    Q_SIGNAL void Finished();

private:
    /**
     * Loads the slide's UI-elements
     * @param index The index of the slide to load
     */
    void LoadQuestionWidget(std::size_t index);

private:
    Q_OBJECT
    
    std::unique_ptr<Ui::QuizWidget> m_UI;            /**< contains the widget gui */
    std::vector<Question> m_Questions;               /**< contains the questions */
    std::vector<std::pair<QString, bool>> m_Results; /**< contains all entered value and if it was correct */
};