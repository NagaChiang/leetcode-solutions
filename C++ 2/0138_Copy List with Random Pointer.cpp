class Solution {
public:
  Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> nodeMap;
    return copyRandomList(head, nodeMap);
  }

  Node* copyRandomList(Node* node, unordered_map<Node*, Node*>& nodeMap) {
    if (node == nullptr) {
      return nullptr;
    }

    if (nodeMap.find(node) != nodeMap.end()) {
      return nodeMap[node];
    }

    Node* clone = new Node(node->val);
    nodeMap[node] = clone;

    clone->next = copyRandomList(node->next, nodeMap);
    clone->random = copyRandomList(node->random, nodeMap);

    return clone;
  }
};