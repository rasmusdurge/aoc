#include <iostream>
#include <fstream>
#include <map>
#include "dayOneUtils.h"

int main() {
    
    std::string str;
    
    std::map<std::string,std::string> numberMap = 
    {{"one","1"},{"two","2"},{"three","3"},
    {"four","4"},{"five","5"},{"six","6"},
    {"seven","7"},{"eight","8"},{"nine","9"}};        
    std::ifstream file("./input.txt");
    int sum = 0;
    while(std::getline(file,str)) {
        std::string translatedString = translateString(str, numberMap);
        std::string line = getNumbersAsString(translatedString);
        std::string res = getFirstAndLastChar(line);
        std:: cout << "Original: " << str << 
        " | " << "Translated: " << translatedString <<
        " | " << "Result: " << res << "\n ";

        int tmp = std::stoi(res);
        sum += tmp;
    }
    std::cout << "Result is: " << sum << "\n";
    return 0;
}