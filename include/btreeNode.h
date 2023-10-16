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

public:
    int findKey(uint64_t key, KeyEntry& keyOut); // returns a reference to the key

    void insertKeyEntry(const KeyEntry& keyEntry); // inserts a key entry in sorted order

    void printElements();
};

}; // BTreeImpl
