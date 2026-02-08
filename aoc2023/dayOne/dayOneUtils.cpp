#include "dayOneUtils.h"
#include <vector>

std::string getFirstAndLastChar(const std::string& inputString) {
    char a = inputString.front();
    char b = inputString.back();
    std::string c{a,b};
    return c;
}

std::string getNumbersAsString(const std::string& str) {
    std::string resultString;
    for (char c : str) {
        if (std::isdigit(c)) {
            resultString = resultString + c;
        }
    }
    return resultString;
}

std::string translateString(const std::string& inputString, 
    const std::map<std::string,std::string>& numberMap) {
    std::string translatedString = inputString;
    bool translated = false;
    while (!translated) {
        
        for (const auto& [key,value] : numberMap) {
        
            bool allNumbersFound = false;

            while (!allNumbersFound) {
                size_t index = translatedString.find(key);
                if (index != std::string::npos) {
                translatedString.replace(index+1,value.length(),value);
            } else {
                allNumbersFound = true;
            }
            }
            translated = true;
        }
    }
    return translatedString;
}



