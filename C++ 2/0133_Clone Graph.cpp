class Solution {
private:
    unordered_map<Node*, Node*> nodeMap;
    
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        
        auto itr = nodeMap.find(node);
        if (itr != nodeMap.end()) {
            return itr->second;
        }
        
        Node* cloneNode = new Node(node->val);
        nodeMap[node] = cloneNode;
        
        for (Node* n : node->neighbors) {
            cloneNode->neighbors.push_back(cloneGraph(n));
        }
        
        return cloneNode;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        
        unordered_map<Node*, Node*> nodeMap;
        vector<Node*> stack;
        stack.push_back(node);
        nodeMap[node] = new Node(node->val);
        while (!stack.empty()) {
            Node* n = stack.back();
            stack.pop_back();
            
            Node* clone = nodeMap[n];
            for (Node* neighbor : n->neighbors) {
                if (nodeMap.find(neighbor) == nodeMap.end()) {
                    nodeMap[neighbor] = new Node(neighbor->val);
                    stack.push_back(neighbor);
                }
                
                clone->neighbors.push_back(nodeMap[neighbor]);
            }
        }
        
        return nodeMap[node];
    }
};