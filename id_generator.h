#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>

class IDGenerator {
private:
    std::map<char, int> alphaMap;
    std::vector<char> alphaVector;

    std::string increaseIdentifier(const std::string& identifier);
    bool checkLastIdentifier(const std::string& identifier);

public:
    IDGenerator();
    std::string generateNextIdentifier(const std::string& identifier);
};