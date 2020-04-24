/**
 * @file DataParser.hpp
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
 * The DataParser file implements a Question struct and Question::LoadQuestions.
 * The json-file reader is cloned from https://github.com/nlohmann/json
 */

#pragma once            // Include guard

#include "json.hpp"     // nlohman::json
#include <fstream>      // std::ifstream
#include <string>       // std::string
#include <vector>       // std::vector

/**
 * @struct Question
 * @brief A data container for the json objects found in the json list
 * @author Noak Palander
 * 
 * The struct Question contains the three components found in each object in the json list.
 * It implements a static function that returns a vector of Question objects.
 */
struct Question {
    std::string question;               /**< Contains the question */
    std::vector<std::string> options;   /**< Contains the options */
    std::string answer;                 /**< Contains the answer */

    /**
     * Loads all the questions found in the json file
     *
     * @param path The filename and path to the json file
     *
     * @return A vector of Question objects 
    */
    inline static std::vector<Question> LoadQuestions(std::string const& path) {
        // Opens the text-file and dumps it into a json object
        std::ifstream file(path.c_str());
        nlohmann::json jsonReader;
        file >> jsonReader;

        // The vector of questions that should be returned
        std::vector<Question> questions;
        // Reserve the inner capacity of the vector, to the size of the json-list
        questions.reserve(jsonReader["qna"].size());

        // Create the objects
        for (auto& i : jsonReader["qna"])
            // In-place constructs updated Question objects
            questions.emplace_back(Question{ i["q"], i["opt"], i["a"] });
        
        // Return the objects
        return questions;
    }
};