#include "btreeNode.h"

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
};
