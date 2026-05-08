#include <iostream>
#include <fstream>
#include <map>
#include <regex>
#include <set>

// Add up all the part numbers
// If its not next to a number or dot 
// Assume parts + symbol combo is unique


bool adjacent(int x1, int x2, int y1, int y2) {
    int dx = std::abs(x2-x1);
    int dy = std::abs(y2-y1);
    return (dx <= 1 && dy <=1);
}

int main() {

    std::ifstream file("./input.txt");
    std::string line;
    
    std::regex numberPattern(R"(\d+)");
    std::map<std::pair<int,int>, int> numberGrid;
    std::map<std::pair<int,int>, std::string> symbolGrid;
    std::set<int> parts;

    int row = 0;
    while(std::getline(file,line)) {
        
        auto numbersIterator = std::sregex_iterator(line.begin(), line.end(), numberPattern);
        auto endLine = std::sregex_iterator();
        
        for (auto i = numbersIterator; i != endLine; ++i) {
            for (int j = 0; j < i->length(); j++) {
                numberGrid[{row,i->position()+j}] = std::stoi(i -> str());
            }    
        }   
        
        int col = 0;
        for (char c : line) {
            if (!std::isdigit(c) && c != '.') {
                symbolGrid[{row,col}] = c;
            }
            col += 1;
        }
        row += 1;
    }

    for (const auto& number : numberGrid) {
        for (const auto& symbol : symbolGrid) {
           if (adjacent(number.first.first,number.first.second,
                    symbol.first.first,symbol.first.second)) {
                        parts.insert(number.second);
            }
        }
    }

    int sum = 0;
    for (int x : parts) {
    sum += x;
    std::cout << x << "\n";
    }
    std::cout << sum << "\n";
    


   
    // 24512 too low

    
    if (!numberGrid.empty()) {
    auto it = numberGrid.begin();

    int x = it->first.first;
    int y = it->first.second;
    int value = it->second;

    

    std::cout << "(" << x << "," << y << ") = " << value << '\n';
    }

    if (!symbolGrid.empty()) {
    auto it = symbolGrid.begin();

    int x = it->first.first;
    int y = it->first.second;
    const std::string& value = it->second;

    std::cout << "(" << x << "," << y << ") = " << value << '\n';
    }

for (const auto& [coord, value] : numberGrid) {
    auto [x, y] = coord;
    //std::cout << "(" << x << "," << y << ") = " << value << '\n';
}

    return 0;
}
