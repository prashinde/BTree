#pragma once

#include <set>

namespace BTreeImpl {

class BTreeNodeTest;

// constants
extern uint64_t g_btreeDegree;
extern uint64_t g_maxBtreeNodes;

class BTreeNode;

// Generic class for key to hold reference to
// the key and its descendands
class KeyEntry {
public:
    uint64_t m_key; // key name
    BTreeNode *m_left; // pointer to the node having keys less than me
    BTreeNode *m_right; // pointer to the node having keys more than me

public:
    KeyEntry(uint64_t key) : m_key(key),
                             m_left(nullptr),
                             m_right(nullptr)
                             { }
                             
    inline bool operator<(const KeyEntry& lhs) const
    {
        return this->m_key < lhs.m_key;
    }
};

// Class for Btree node
class BTreeNode {
    friend class BTreeNodeTest;
private:
    std::set<KeyEntry> m_keys; // series of keys
    uint64_t m_numKeys; // number of keys
    bool m_isLeafNode;

public:
    BTreeNode() : m_numKeys(0), m_isLeafNode(true)
    { }

    int findKey(uint64_t key, KeyEntry& keyOut); // returns a reference to the key

    void insertKeyEntry(const KeyEntry& keyEntry); // inserts a key entry in sorted order

    void printElements(); // print elements

    // Split the current node at the given interval
    // Returns the new node
    std::shared_ptr<BTreeNode> splitNode(uint32_t percentile = 50);

    // inserts a value to the Btree
    // Returns a new key entry if split otherwise null
    KeyEntry insertValue(uint64_t value);
};

}; // BTreeImpl
