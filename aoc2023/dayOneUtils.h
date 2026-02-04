#pragma once
#include <string>
#include <map>
std::string getFirstAndLastChar(const std::string& inputString); 
std::string getNumbersAsString(const std::string& str);
std::string translateString(const std::string& inputString, const std::map<std::string,std::string>& numberMap);