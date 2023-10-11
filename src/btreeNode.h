#pragma once

#include <set>

namespace BTreeNode {

// constants
extern uint64_t g_btreeDegree;
extern uint64_t g_maxBtreeNodes;

class BTreeNode;

// Generic class for key to hold reference to
// the key and its descendands
class KeyEntry {
public:
    uint64_t m_key; // key name
    BTreeNode *left; // pointer to the node having keys less than me
    BTreeNode *right; // pointer to the node having keys more than me

public:
    inline bool operator<(const KeyEntry& lhs, const KeyEntry& rhs)
    {
        return lhs.m_key < rhs.m_key;
    }
};

// Class for Btree node
class BTreeNode {
private:
    std::set<KeyEntry> m_keys; // series of keys
    uint64_t m_numKeys; // number of keys

private:
    const KeyEntry& findKey(uint64_t key); // returns a reference to the key
};

};
