/**
 * @file main.cpp
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
 * The main file contains the main function, initializes the qapplication and constructs the mainwindow
 * 
 * @see MainWindow.hpp
 */

// If platform is windows
#ifdef _WIN32
    // Only allow compilation if the compiler standard-version is c++17
    #if _MSVC_LANG < 201703L
        #error Please use a compiler which supports c++17!
    #endif
// If the platform is linux
#else
    // Only allow compilation if the compiler standard-version is c++17
    #if __cplusplus != 201703L
        #error Please use a compiler which supports c++17!
    #endif
#endif

#include "window/MainWindow.hpp"    // MainWindow
#include <QApplication>             // QApplication

int main(int argc, char** argv) {
    // Sets up the qt-application
    QApplication a(argc, argv);

    // Constructs and displays the mainwindow
    MainWindow w{};
    w.show();
    return a.exec();
}