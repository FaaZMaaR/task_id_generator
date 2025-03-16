#include "id_generator.h"

IDGenerator::IDGenerator() {
    char letter = 'A';
    int id = 0;
    while (letter <= 'Z') {
        if (letter != 'D' && letter != 'F' && letter != 'G' && letter != 'J' && letter != 'M' && letter != 'Q' && letter != 'V') {
            alphaMap[letter] = id++;
            alphaVector.push_back(letter);
        }
        ++letter;
    }
}

std::string IDGenerator::increaseIdentifier(const std::string& identifier) {
    std::string new_id = identifier;
    if (identifier[1] == '9') {
        if (identifier[0] == 'Z') {
            new_id = "A1";
        }
        else {
            new_id[0] = alphaVector[alphaMap[identifier[0]] + 1];
            new_id[1] = '1';
        }
    }
    else {
        new_id[1] = identifier[1] + 1;
    }
    return new_id;
}

bool IDGenerator::checkLastIdentifier(const std::string& identifier) {
    if (identifier.size() < 29) {
        return false;
    }
    for (int i = 0; i < identifier.size(); ++i) {
        if ((identifier[i] != 'Z' && identifier[i] != '9') && identifier[i] != '-') {
            return false;
        }
    }
    return true;
}

std::string IDGenerator::generateNextIdentifier(const std::string& identifier) {
    if (checkLastIdentifier(identifier)) {
        throw std::runtime_error("maximum identifier reached");
    }
    std::string new_id = identifier;
    int groups = identifier.size() / 3 + 1;
    std::string single_id;
    std::string new_single_id;
    bool overflow = false;
    for (int i = 0; i < groups; ++i) {
        single_id = "";
        single_id += identifier[identifier.size() - 2 - i * 3];
        single_id += identifier[identifier.size() - 1 - i * 3];
        new_single_id = increaseIdentifier(single_id);
        new_id[new_id.size() - 2 - i * 3] = new_single_id[0];
        new_id[new_id.size() - 1 - i * 3] = new_single_id[1];
        if (new_single_id == "A1") {
            overflow = true;
        }
        else {
            overflow = false;
            break;
        }
    }
    if (overflow) {
        new_id += "-A1";
    }
    return new_id;
}