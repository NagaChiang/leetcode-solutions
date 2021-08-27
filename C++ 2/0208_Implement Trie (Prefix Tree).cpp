struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    
    TrieNode() {
        memset(children, 0, sizeof(children));
        isEnd = false;
    }
};

class Trie {
private:
    TrieNode* root = nullptr;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(const string& word) {
        TrieNode* node = root;
        for (const char c : word) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            
            node = node->children[index];
        }
        
        node->isEnd = true;
    }

    bool search(const string& word) {
        TrieNode* node = findPrefixEnd(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(const string& prefix) {
        return findPrefixEnd(prefix) != nullptr;
    }

private:
    TrieNode* findPrefixEnd(const string& prefix) {
        TrieNode* node = root;
        for (const char c : prefix) {
            node = node->children[c - 'a'];
            if (node == nullptr) {
                return nullptr;
            }
        }
        
        return node;
    }
};