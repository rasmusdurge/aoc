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

    
    int sum = 0;
    int counter = 1;
    while (std::getline(file,str)) {
        
        bool possible = true;
        auto allMatches = std::sregex_iterator(str.begin(),str.end(),pattern);
        auto matchesEnd = std::sregex_iterator();

        for (std::sregex_iterator it = allMatches; it != matchesEnd; ++it) {
            int value = std::stoi((*it)[1]);
            std::string color = (*it)[2];

            if (color == "blue" && value > blues) {
                possible = false;
            }

              if (color == "red" && value > reds) {
                possible = false;
            }

              if (color == "green" && value > greens) {
                possible = false;
            }
        }
 
        if (possible) {
            sum += counter;
        }
        
        counter += 1;
    }
    std::cout << sum << "\n";
}

// Correct answer = 2449

