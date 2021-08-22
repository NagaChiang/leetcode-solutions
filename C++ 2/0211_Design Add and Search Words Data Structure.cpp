// Trie
class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEndOfWord;
        
        TrieNode() {
            for (TrieNode*& child : children) {
                child = nullptr;
            }
            
            isEndOfWord = false;
        }
    };
    
    typedef struct TrieNode TrieNode;
    
private:
    TrieNode* root;
    
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            
            node = node->children[index];
        }
        
        node->isEndOfWord = true;
    }
    
    bool search(string word) {
        return searchFromNode(root, word.c_str());
    }
    
private:
    bool searchFromNode(TrieNode* node, const char* word) {
        if (word[0] == '\0') {
            return node->isEndOfWord;
        }
        
        if (word[0] == '.') {
            for (TrieNode* n : node->children) {
                if (n != nullptr && searchFromNode(n, word + 1)) {
                    return true;
                }
            }
            
            return false;
        } else {
            int index = word[0] - 'a';
            if (node->children[index] != nullptr) {
                node = node->children[index];
                return searchFromNode(node, word + 1);
            } else {
                return false;
            }
        }
    }
};

// Map
class WordDictionary {
private:
    unordered_map<int, vector<string>> wordMap;
    
public:
    WordDictionary() {}
    
    void addWord(string word) {
        wordMap[word.size()].push_back(word);
    }
    
    bool search(string word) {
        for (const string& w : wordMap[word.size()]) {
            if (isEqual(word, w)) {
                return true;
            }
        }
        
        return false;
    }
    
private:
    bool isEqual(const string& a, const string& b) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == '.') {
                continue;
            }

            if (a[i] != b[i]) {
                return false;
            }
        }
        
        return true;
    }
};