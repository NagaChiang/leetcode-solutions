class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode preHead = ListNode(0, head);
    ListNode* slow = &preHead;
    ListNode* fast = &preHead;
    for (int i = 0; i < n; i++) {
      fast = fast->next;
    }

    while (fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next;
    }

    ListNode* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;

    return preHead.next;
  }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode** slowPtr = &head;
        ListNode* fast = head;
        for (int i = 0; i < n - 1; i++) {
            fast = fast->next;
        }
        
        while (fast->next != nullptr) {
            slowPtr = &((*slowPtr)->next);
            fast = fast->next;
        }
        
        ListNode* removeNode = *slowPtr;
        *slowPtr = (*slowPtr)->next;
        delete removeNode;
        
        return head;
    }
};