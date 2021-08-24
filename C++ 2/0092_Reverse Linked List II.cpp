class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode preHead = ListNode();
        preHead.next = head;
        
        ListNode* preLeftNode = &preHead;
        for (int i = 0; i < left - 1; i++) {
            preLeftNode = preLeftNode->next;
        }
        
        ListNode* node = preLeftNode->next;
        for (int i = 0; i < right - left; i++) {
            ListNode* next = node->next;
            node->next = next->next;
            next->next = preLeftNode->next;
            preLeftNode->next = next;
        }
        
        return preHead.next;
    }
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode preHead = ListNode();
        preHead.next = head;
        
        ListNode* preLeftNode = &preHead;
        for (int i = 0; i < left - 1; i++) {
            preLeftNode = preLeftNode->next;
        }
        
        ListNode* rightNode = preLeftNode;
        for (int i = 0; i < right - (left - 1); i++) {
            rightNode = rightNode->next;
        }
        
        ListNode* leftNode = preLeftNode->next;
        ListNode* postRightNode = rightNode->next;
        preLeftNode->next = nullptr;
        rightNode->next = nullptr;
        reverseList(leftNode);
        
        leftNode->next = postRightNode;
        preLeftNode->next = rightNode;
        
        return preHead.next;
    }
    
    ListNode* reverseList(ListNode* node) {        
        ListNode* last = nullptr;
        while (node != nullptr) {
            ListNode* next = node->next;
            node->next = last;
            
            last = node;
            node = next;
        }
        
        return last;
    }
};