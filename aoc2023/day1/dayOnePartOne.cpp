#include <iostream>
#include <fstream>
#include <string>
#include "dayOneUtils.h"

int main() {
    std::ifstream file("./input.txt");
    std::string str;
    int sum = 0;
    while(std::getline(file,str)) {
        std::string line = getNumbersAsString(str);
        std::string res = getFirstAndLastChar(line);
        //std::cout << res << "\n";
        int tmp = std::stoi(res);
        sum += tmp;
    }
    std::cout << "Result is: " << sum << "\n";
    return 0;
    // Result - > 53651
}

