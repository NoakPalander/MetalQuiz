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
 * The QuizWidget source file implements the QuizWidget class and sets up it's children. It's visual config is auto generated
 *  and defined in ui_QuizWidget.h and QuizWidget.ui. The declaration of QuizWidget.cpp is in QuizWidget.hpp.
 * 
 * The QuizWidget object will display each slide, these slide contains a label of the question, radiobuttons for the options,
 *  and a next button, to advance the quiz.
 * 
 * @see QuizWidget.ui
 * @see ui_QuizWidget.h
 * @see QuizWidget.hpp
 */

#include "QuizWidget.hpp"       // QuizWidget
#include "./ui_QuizWidget.h"    // Ui::QuizWidget
#include <QRadioButton>         // QRadioButton
#include "../Style.hpp"         // Style::LoadWidgetStyle

#include <algorithm>            // std::shuffle
#include <random>               // std::random_device, std::default_random_engine

/**
 * Constructor that constructs the quiz widget and sets it's slides
 * 
 * @param parent The parent QWidget-object of the class, default initialized to nullptr
 */
QuizWidget::QuizWidget(QWidget* parent) 
    :   QWidget(parent),
        m_UI(std::make_unique<Ui::QuizWidget>()),
        m_Questions(Question::LoadQuestions("../resources/questions.json")),
        m_Results{}
{
    m_UI->setupUi(this);
    Style::LoadWidgetStyle(*this, "../resources/styles.qss");

    // Scrambles the vector using the default random engine
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::shuffle(std::begin(m_Questions), std::end(m_Questions), rng);

    LoadQuestionWidget(0);

    // Binds the QPushButton::pressed(m_UI->nextBtn) signal to a mutable lambda as slot
    // The lambda needs to be mutable for it to be able to modify the copied-captured index
    // The lambda also captures [this], as otherwise it can't call LoadQuestionWidget
    connect(m_UI->nextBtn, &QPushButton::pressed, this, [this, index = 0u]() mutable {
        bool hasButtonChecked = false;

        // Check if the option was correct
        for (QRadioButton* btn : this->findChildren<QRadioButton*>()) {
            // If the selected radiobutton's text is the same as the answer, add it as a correct answer 
            if (btn->isChecked()) {
                // Appends the the answer(QString) and if it was correct(bool) 
                m_Results.emplace_back(btn->text(), btn->text().toStdString() == m_Questions[index].answer);
                hasButtonChecked = true;
                break; // no need to keep searching, only 1 radiobutton CAN be selected
            }
        }        

        if (hasButtonChecked) {
            // The last question answered, now instead view the result page
            if (index == m_Questions.size() - 1) {
                // Calls the corresponding slot
                Finished();
            }
            else {
                // Update the button to instead take results
                if (index + 1 == m_Questions.size() - 1)
                    m_UI->nextBtn->setText("Results");

                // Loads the next question (and increments the index)
                LoadQuestionWidget(++index);
            }
        }
    });
}

/**
 * Destructor that destroys the quiz widget
 */
QuizWidget::~QuizWidget() {}

/**
 * Gets the results of the slide i.e the user's entered option
 * 
 * @param index The question index
 * @returns A std::tuple containing the question, answer, and selected option for the passed index
 */
std::tuple<QString, QString, QString> QuizWidget::GetResults(std::size_t index) const {
    return { QString::fromStdString(m_Questions[index].question), // question
             QString::fromStdString(m_Questions[index].answer),   // answer
             m_Results[index].first                               // entered answer
    };
}

/**
 * Gets the total score calculated by all slides 
 * 
 * @returns An std::size_t containing score
 */
std::size_t QuizWidget::GetScore() const {
    // Returns the sum of all bools in the results-vector (score)
    return std::accumulate(std::begin(m_Results), std::end(m_Results), 0, 
        [](std::size_t prev, std::pair<QString, bool> p) -> std::size_t {  
            return prev + p.second;
    });
}

/**
 * Gets the number of questions in the quiz
 * 
 * @returns An std::size_t containing the number of quiz-slides
 */
std::size_t QuizWidget::GetLength() const {
    return m_Questions.size();
}

/**
 * Loads the slide's UI-elements
 * @param index The index of the slide to load
 */
void QuizWidget::LoadQuestionWidget(std::size_t index) {
    // Sets the question text, QLabels require QStrings not std::string, so we convert it
    m_UI->questionLabel->setText(QString::fromStdString(m_Questions[index].question));
    
    // Finds the horizontal layout where the radiobuttons are gonna be placed
    QHBoxLayout* hbox = this->findChild<QHBoxLayout*>("optionsLayout");
    
    // Clears all the old buttons
    for (QRadioButton* btn : this->findChildren<QRadioButton*>())
        delete btn;

    // Creates radiobuttons with the option as it's label
    for (std::string const& option : m_Questions[index].options) {
        QRadioButton* btn = new QRadioButton(QString::fromStdString(option));
        btn->setAccessibleName("options");
        hbox->addWidget(btn);
    }
}