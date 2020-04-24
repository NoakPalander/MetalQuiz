/**
 * @file Style.hpp
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
 * The Style file declares and implements a loading function that loads a stylesheet (.qss) and applies it to the widget reference passed
 */

#pragma once            // Include guard

// Checks the compiler version
#if __GNUC__ < 8 || __clang__ == 1 && __clang_major__ < 6
    // Includes filesystem from experimental
    #include <experimental/filesystem>
    namespace fs = std::experimental::filesystem;
#else
    // Includes filesystem from stable
    #include <filesystem>
    namespace fs = std::filesystem;
#endif

#include <QString>      // QString
#include <QMessageBox>  // QMessageBox
#include <QWidget>      // QWidget
#include <fstream>      // std::ifstream
#include <sstream>      // std::stringstream

namespace Style {
    /**
     * @namespace Style
     * @param widget The widget that the stylesheet should be applied to
     * @param file The filepath and name containing the stylesheet
     */
    static void LoadWidgetStyle(QWidget& widget, const char* file) {
        static std::stringstream s_Stream;

        // First time being called ever
        if (s_Stream.str().empty()) {
            std::ifstream reader(file);
            if (fs::exists(file)) {
                s_Stream << reader.rdbuf();
                widget.setStyleSheet(QString::fromStdString(s_Stream.str()));
            }
            else {
                QMessageBox mb(
                    QMessageBox::Icon::Warning, 
                    "Failed to load file!",
                    QString("Failed to load '%1' as a stylesheet! Make sure the file is in the right path!\nDefaulting to normal stylesheet!").arg(file),
                    QMessageBox::StandardButton::Ok);
                
                mb.exec();
            }
        }
        // Else, just apply the stylesheet to the widget
        else {
            widget.setStyleSheet(QString::fromStdString(s_Stream.str()));
        }
    }
};