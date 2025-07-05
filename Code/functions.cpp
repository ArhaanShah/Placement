#include "functions.hpp"


std::string stripWhitespace(const std::string& inputString) {
    std::string result = inputString; 

    size_t firstNonSpace = result.find_first_not_of(" \t\n\r");
    if (firstNonSpace != std::string::npos)
        result.erase(0, firstNonSpace);

    size_t lastNonSpace = result.find_last_not_of(" \t\n\r");
    if (lastNonSpace != std::string::npos)
        result.erase(lastNonSpace + 1);

    return result;
}

std::string toLowercase(const std::string& inputString) {
    std::string result = inputString; 

    std::transform(result.begin(), result.end(), result.begin(),
                    [](unsigned char c) { return std::tolower(c); });

    return result;
}

std::string fD(const std::string& inputString) {    
    return toLowercase(stripWhitespace(inputString));
}