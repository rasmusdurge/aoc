#include <iostream>
#include <fstream>
#include "day4Utils.h"

int main () {

    std::ifstream file("./input.txt");
    std::string line;
    
    int sum = 0;
    int row = 0;
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

        sum += winCount;
 
        if (winCount == 0) {
            sum += 1;
        }
        
        row += 1;
        std::cout << "Winners for Card " << row << ": " <<  winCount << "\n";
        
    }
    std::cout << sum << "\n";
    
    return 0;
}

// 906 too low

// 937 too low


