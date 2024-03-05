//
// Created by lucas on 15.11.23.
//

#include "StringUtils.h"


std::vector<std::string> StringUtils::split_string(const std::string& s, const char delimiter, std::string_view ignore) {

    std::vector<std::string> res{};

    std::string word{};

    for (const auto c : s)
    {
        if (c == delimiter)
        {
            res.push_back(word);
            word = "";
        }
        else if (ignore.find(c) == std::string::npos)
        {
            word += c;
        }
    }

    if (!word.empty())
    {
        res.push_back(word);
    }

    return res;
}
