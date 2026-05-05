#include <iostream>
#include <fstream>
#include <regex>

int main() {

    int reds = 12;
    int greens = 13;
    int blues = 14;

    std::ifstream file("./input.txt");
    std::string str;

    std::regex pattern(R"((\d+)\s+(blue|red|green))");
    
   
    int power = 0;
    while (std::getline(file,str)) {
        
    
        auto matches = std::sregex_iterator(str.begin(),str.end(),pattern);
        auto matchesEnd = std::sregex_iterator();

        int maxBlue = 0;
        int maxRed = 0;
        int maxGreen = 0;

        for (std::sregex_iterator it = matches; it != matchesEnd; ++it) {
            int value = std::stoi((*it)[1].str());
            std::string color = (*it)[2].str();

            if (color == "blue") {
               maxBlue =  std::max(maxBlue,value);
            }

            if (color == "red") {
                maxRed = std::max(maxRed,value);
            }

            if (color == "green") {
                maxGreen = std::max(maxGreen,value);
            }           
        }
            
        power += maxBlue * maxRed * maxGreen;
    
    }
    std::cout << power << "\n";
}

// Correct answer = 63981