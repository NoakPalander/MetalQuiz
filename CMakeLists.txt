cmake_minimum_required(VERSION 3.5)

project(Quiz LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(Quiz
    src/main.cpp
    src/window/MainWindow.cpp
    src/window/MainWindow.hpp
    src/quiz/QuizWidget.cpp
    src/quiz/QuizWidget.hpp
    src/result/ResultWidget.cpp
    src/result/ResultWidget.hpp
    src/result/page/PageWidget.cpp
    src/result/page/PageWidget.hpp
    src/result/score/ScoreWidget.cpp
    src/result/score/ScoreWidget.hpp
    src/Style.hpp
    src/Question.hpp
    src/json.hpp
)

target_link_libraries(Quiz PUBLIC Qt5::Widgets stdc++fs)

if (WIN32)
    find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS "${_qt_bin_dir}")
    add_custom_command(TARGET Quiz POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E
            env PATH="${_qt_bin_dir}" "${WINDEPLOYQT_EXECUTABLE}"
                "$<TARGET_FILE:Quiz>"
        COMMENT "Running windeployqt..."
    )
endif()