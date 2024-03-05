//
// Created by lucas on 15.11.23.
//

#ifndef ODESOLVER_STRINGUTILS_H
#define ODESOLVER_STRINGUTILS_H

#include <string>
#include <vector>
#include <string_view>


namespace StringUtils {

    // TODO: should be faster with string_view.
    std::vector<std::string> split_string(const std::string &s, char delimiter, std::string_view ignore);

};


#endif //ODESOLVER_STRINGUTILS_H
