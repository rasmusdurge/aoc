#include "day4Utils.h"
#include <vector>

std::vector<int> readIntoVector(std::istringstream& numbers) {
    std::vector<int> result;
    int x;
    while (numbers >> x) {
        result.push_back(x);
    }
    return result;
}