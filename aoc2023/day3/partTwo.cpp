#include <iostream>
#include <fstream>
#include <map>
#include <regex>
#include <set>
#include <vector>

struct Part {
    std::string number;
    int xcord;
    int ycord;

    Part(std::string n,int x, int y) {
        number = n;
        xcord = x;
        ycord = y;
    }
};

struct Symbol {
    char symbol;;
    int xcord;
    int ycord;

    Symbol(char n, int x, int y) {
        symbol = n;
        xcord = x;
        ycord = y;
    }
};

bool adjacent(int x1, int y1, int x2, int y2) {
    int dx = std::abs(x1-x2);
    int dy = std::abs(y1-y2);
    return (dx <= 1 && dy <=1 && !(dx == 0 && dy == 0 ));
}

int calculateSum(std::vector<Part> parts, std::vector<Symbol> symbols) {
    int sum = 0;

    // loop over the gears instead
    for (const auto& s : symbols) {
        // check clockwise.
        // I think use map and lookups.
    }
    return sum;
}

int main() {

    std::ifstream file("./input.txt");
    std::string line;
    
    std::regex numberPattern(R"(\d+)");
    std::vector<Part> parts;
    std::vector<Symbol> symbols;

    int row = 0;
    while(std::getline(file,line)) {
        
        // store parts
        auto numbersIterator = std::sregex_iterator(line.begin(), line.end(), numberPattern);
        auto endLine = std::sregex_iterator();
        for (auto i = numbersIterator; i != endLine; ++i) {
              parts.push_back(Part(i->str(),row,i->position()));
            }    

        // store gears *
        int col = 0;
        for (char c : line) {
            if (c == '*') {
                symbols.push_back(Symbol(c,row,col));
            }
        col += 1;
        }

        row += 1;
       
    }
    
int result = calculateSum(parts,symbols);
std::cout << result << "\n";
return 0;

}




