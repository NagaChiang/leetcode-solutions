class Codec {
public:
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "x,";
        }
        
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    TreeNode* deserialize(string data) {
        deque<string> tokens;
        char* token = strtok(strdup(data.c_str()), ",");
        while (token != nullptr) {
            tokens.push_back(string(token));
            token = strtok(nullptr, ",");
        }
        
        TreeNode* root = nullptr;
        convertToTree(root, tokens);
        
        return root;
    }
    
    void convertToTree(TreeNode*& node, deque<string>& tokens) {
        if (tokens.empty()) {
            return;
        }
        
        string token = tokens.front();
        tokens.pop_front();
        
        if (token == "x") {
            node = nullptr;
            return;
        }
        
        int value = stoi(token);
        node = new TreeNode(value);
        convertToTree(node->left, tokens);
        convertToTree(node->right, tokens);
    }
};