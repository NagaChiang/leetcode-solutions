class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        unordered_set<ListNode*> nodeSet;

        int index = 1;
        ListNode* node = head;
        while (node != nullptr) {
            if (nodeSet.find(node) != nodeSet.end()) {
                return node;
            }

            nodeSet.insert(node);
            index++;

            node = node->next;
        }

        return nullptr;
    }
};

// Meet after n rounds (b + c)
// a + n(b + c) + b = 2(a + b)
// a + nb + nc + b = 2a + 2b
// nb + nc - b = a
// nb + nc - b + c - c = a
// b(n - 1) + c(n - 1) + c = a 
// So, if the slow pointer keeps going, it finally meets the new pointer from the start
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        bool hasCycle = false;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                hasCycle = true;
                break;
            }
        }

        if (hasCycle) {
            ListNode* node = head;
            while (node != slow) {
                node = node->next;
                slow = slow->next;
            }

            return node;
        }

        return nullptr;
    }
};