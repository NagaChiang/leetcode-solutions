#include <stdlib.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{

public:

	bool isPalindrome(ListNode* head)
	{
		if(!head)
			return true;

		// Use slow and fast pointers to find the second half
		ListNode* slow = head;
		ListNode* fast = head;
		while(fast->next && fast->next->next)
		{
			// Move fast pointer 2 nodes forward
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode* halfHead = slow->next;

		// Reverse second half
		halfHead = reverseList(halfHead);

		// Compare
		ListNode* node1 = head;
		ListNode* node2 = halfHead;
		while(node1 && node2)
		{
			if(node1->val != node2->val)
				return false;

			node1 = node1->next;
			node2 = node2->next;
		}

		return true;
	}

private:

	ListNode* reverseList(ListNode* head)
	{
		ListNode* lastNode = NULL;
		ListNode* node = head;
		while(node != NULL)
		{
			// Reverse
			ListNode* nextNode = node->next;
			node->next = lastNode;

			// Move pointers
			lastNode = node;
			node = nextNode;
		}

		return lastNode;
	}
};