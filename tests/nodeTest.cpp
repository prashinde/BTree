#include <iostream>
#include "btreeNode.h"

using namespace BTreeImpl;
int main()
{
    std::cout << "hello" << std::endl;
    BTreeNode node;

    // make 10 key entries
    for (int i = 0; i < 10; i++) {
        node.insertKeyEntry(KeyEntry(1));
    }
    return 0;
}
