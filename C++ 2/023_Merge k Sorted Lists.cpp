class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int interval = 1;
        while (interval < lists.size()) {
            for (int i = 0; i < lists.size() - interval; i += interval * 2) {
                lists[i] = mergeLists(lists[i], lists[i + interval]);
            }
            
            interval *= 2;
        }
        
        return lists.size() > 0 ? lists[0] : nullptr;
    }
    
    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        
        if (l2 == nullptr) {
            return l1;
        }
        
        ListNode* node1 = l1;
        ListNode* node2 = l2;
        ListNode newPreRoot;
        ListNode* tail = &newPreRoot;
        while (node1 != nullptr && node2 != nullptr) {
            if (node1->val < node2->val) {
                tail->next = node1;
                node1 = node1->next;
            } else {
                tail->next = node2;
                node2 = node2->next;
            }
            
            tail = tail->next;
        }
        
        tail->next = node1 != nullptr ? node1 : node2;
        
        return newPreRoot.next;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> queue(compare);
        for (ListNode* node : lists) {
            if (node == nullptr) {
                continue;
            }
            
            queue.push(node);
        }
        
        ListNode* sortedRoot = nullptr;
        ListNode* sortedNode = nullptr;
        while (!queue.empty()) {
            ListNode* node = queue.top();
            queue.pop();
            
            if (sortedNode == nullptr) {
                sortedRoot = node;
                sortedNode = sortedRoot;
            } else {
                sortedNode->next = node;
                sortedNode = sortedNode->next;
            }
            
            if (node->next != nullptr) {
                queue.push(node->next);
            }
        }
        
        return sortedRoot;
    }
};