/**
 * @file ScoreWidget.hpp
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
 * The ScoreWidget header file declares the ScoreWidget class and sets up it's children. It's visual config is auto generated
 *  and defined in ui_ScoreWidget.hpp and ScoreWidget.ui. The implementation of ScoreWidget.hpp is in ScoreWidget.cpp. 
 * 
 * The ScoreWidget object will display the total percentage of the questions answered correctly, and an image if the rate is above
 *  a certain threshold.
 * 
 * @see ui_ScoreWidget.h
 * @see ScoreWidget.ui
 * @see ScoreWidget.cpp
 */

#pragma once        // Include guard

#include <QWidget>  // QWidget
#include <memory>   // std::unique_ptr

// Forward declares Ui::ScoreWidget
namespace Ui {
    class ScoreWidget;
}

/**
 * @class ScoreWidget
 * @brief Implements a "sumary" widget that displays the total percentage of the questions answered correctly, 
 *  and an image if the rate is above a certain threshold.
 * 
 * @extends QWidget
 * 
 * @see ui_ScoreWidget.h
 * @see ScoreWidget.ui
 * @see ScoreWidget.cpp
 */
class ScoreWidget : public QWidget {
public:
    /**
     * Constructor that constructs the score widget and sets it's children
     * 
     * @param score The score for the slide
     * @param length The amount of slides (questions)
     * @param parent The parent object of the class, default initialized to nullptr
     */
    explicit ScoreWidget(std::size_t score, std::size_t length, QWidget* parent = nullptr);
    
    /**
     * Destructor that destroys the score widget
     */
    ~ScoreWidget();

private:
    Q_OBJECT
    std::unique_ptr<Ui::ScoreWidget> m_UI;  /**< contains the object of the widget gui */ 
};