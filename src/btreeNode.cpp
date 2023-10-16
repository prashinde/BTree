#include "btreeNode.h"
#include "logger.h"

namespace BTreeImpl {

int BTreeNode::findKey(uint64_t key, KeyEntry& keyOut)
{
    auto element = m_keys.find(KeyEntry(key));
    if (element == m_keys.end()) {
        return ENOENT;
    }

    keyOut = *element;
    return 0;
}

void BTreeNode::insertKeyEntry(const KeyEntry& keyEntry)
{
    m_keys.insert(keyEntry);
}

void BTreeNode::printElements()
{
    for (auto key : m_keys) {
        BTreeLogger::Logger::getLogger()->info("key:{}", key.m_key);    
    }
}

std::shared_ptr<BTreeNode> BTreeNode::splitNode(uint32_t percentile)
{
    // calculate how many elements to move
    std::shared_ptr<BTreeNode> newNode = std::make_shared<BTreeNode>();

    uint32_t totalToMove = m_keys.size()/2;
    uint32_t numMoved = 0;

    // new node is empty
    if (totalToMove <= 0) {
        return newNode;
    }
    // Move last elements and while moving remove then from set
    auto rit = m_keys.rbegin();
    while (rit != m_keys.rend()) {
        // move elements to new node
        newNode->insertKeyEntry(*rit);
        numMoved++;

        // remove moved element from iterator
        rit = decltype(rit)(m_keys.erase(std::next(rit).base()));
        // do not touch rit again
        if (numMoved == totalToMove) {
            break;
        }
    }

    return newNode;
}

KeyEntry BTreeNode::insertValue(uint64_t value)
{
    if (m_isLeafNode) {
        if (m_numKeys < g_btreeDegree
    }
}
};
