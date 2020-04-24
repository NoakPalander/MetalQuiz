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
 * The PageWidget header file declares the PageWidget class and sets up it's children. It's visual config is auto generated
 *  and defined in ui_PageWidget.h and PageWidget.ui. The implementation of PageWidget.hpp is in PageWidget.cpp.
 * 
 * Each PageWidget object will display the question, the correct answer, and the entered answer, the entered answer will
 *  be colored as either red or green depending on if it was correct or not.
 * 
 * @see PageWidget.ui
 * @see ui_PageWidget.h
 * @see PageWidget.cpp
 */

#pragma once        // Include guard

#include <QWidget>  // QWidget
#include <QString>  // QString
#include <memory>   // std::unique_ptr

// Forward declares Ui::PageWidget
namespace Ui {
    class PageWidget;
}

/**
 * @class PageWidget
 * @brief Implements the page widget and that sets up the child widgets.
 * @extends QWidget
 * 
 * PageWidget is a of child of the ResultWidget, it's initialized in the scroll widget.
 * 
 * @see PageWidget.ui
 * @see ui_PageWidget.h
 * @see PageWidget.cpp
 */
class PageWidget : public QWidget {
public:
    /**
     * Constructor that constructs a page widget and sets it's quiz labels
     * 
     * @param index The question index
     * @param question The question label
     * @param ans The answer to the question
     * @param correct The correct answer to the question
     * @param parent The parent QWidget-object of the class, default initialized to nullptr
     */
    explicit PageWidget(std::size_t index, QString const& question, QString const& correct, QString const& ans, 
        QWidget* parent = nullptr);
    
    /**
     * Destructor that destroys the page widget and the gui
     */
    ~PageWidget();

private:
    Q_OBJECT
    std::unique_ptr<Ui::PageWidget> m_UI;   /**< contains the object of the widget gui */
};
