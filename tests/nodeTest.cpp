#include <iostream>
#include <random>

#include "btreeNode.h"
#include "logger.h"

using namespace BTreeImpl;

int main()
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(1, 20); // define the range

    BTreeNode node;

    // make 10 key entries
    for (int i = 0; i < 10; i++) {
        node.insertKeyEntry(KeyEntry(distr(gen)));
    }

    BTreeLogger::Logger::getLogger()->info("Printing before split");
    node.printElements();

    auto newNode = node.splitNode();

    BTreeLogger::Logger::getLogger()->info("Printing old node after split");
    node.printElements();
    BTreeLogger::Logger::getLogger()->info("Printing new node after split");
    newNode->printElements();
    return 0;
}
