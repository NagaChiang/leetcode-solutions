// Trie
struct TrieNode {
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        memset(children, 0, sizeof(children));
        isEnd = false;
    }
};

class WordDictionary {
private:
    TrieNode* root = nullptr;

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

        node->isEnd = true;
    }
    
    bool search(string word) {
        return search(word, root);
    }

private:
    bool search(string word, TrieNode* node) {
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (c == '.') {
                for (TrieNode* child : node->children) {
                    if (child != nullptr && search(word.substr(i + 1, word.size()), child)) {
                        return true;
                    }
                }

                return false;
            }

            int index = c - 'a';
            if (node->children[index] != nullptr) {
                node = node->children[index];
            } else {
                return false;
            }
        }

        return node->isEnd;
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