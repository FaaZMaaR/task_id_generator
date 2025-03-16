#include "id_generator.h"

int main() {
    IDGenerator idgen;
    std::cout << idgen.generateNextIdentifier("B5") << std::endl;
    std::cout << idgen.generateNextIdentifier("A1-Z9") << std::endl;
    std::cout << idgen.generateNextIdentifier("S4-C6-L9") << std::endl;
    std::cout << idgen.generateNextIdentifier("Z9-Z9-Z9") << std::endl;
    try {
        std::cout << idgen.generateNextIdentifier("Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9") << std::endl;
    }
    catch (const std::exception& err) {
        std::cout << err.what() << std::endl;
    }
}