#include "day4Utils.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>


int calculateSum(int n) {
    return std::pow(2,n-1);
}

int main() {
    std::ifstream file("./input.txt");
    std::string line;
    
    int sum = 0;
    while(std::getline(file,line)) {

        std::vector<int> winners;
        std::vector<int> lottery;

        int cardBegin = line.find(":");
        int lotteryNumbersBegin = line.find("|");
        
        std::string winnerString = line.substr(cardBegin+1,lotteryNumbersBegin-cardBegin-1);
        std::string lotteryString = line.substr(lotteryNumbersBegin+1);
        std::istringstream winningNumbers(winnerString);
        std::istringstream lotteryNumbers(lotteryString);
        

        
        winners = readIntoVector(winningNumbers);
        lottery = readIntoVector(lotteryNumbers);

        int winCount = 0;
        for (int i : winners) {
            for (int j : lottery) {
                if (i - j == 0) {
                    winCount += 1;
                }
            }
        }
        
        if (winCount != 0) {
            sum += calculateSum(winCount);
        }

    }

    std::cout << sum << "\n";
    return 0;
}

// 24542