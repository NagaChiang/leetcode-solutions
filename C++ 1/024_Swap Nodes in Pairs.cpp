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

	ListNode* swapPairs(ListNode* head)
	{
		if(!head || !head->next)
			return head;

		ListNode* preHead = new ListNode(0);
		preHead->next = head;
		ListNode* node = preHead;
		while(node->next && node->next->next)
		{
			// Swap
			ListNode* nextPair = node->next->next->next;
			node->next->next->next = node->next;
			node->next = node->next->next;
			node->next->next->next = nextPair;

			// Node before next pair
			node = node->next->next;
		}

		return preHead->next;
	}
};

class Solution
{

public:

	ListNode* swapPairs(ListNode* head)
	{
		// New head
		ListNode* newHead = head;
		if(head && head->next)
			newHead = head->next;

		// Swap in pairs
		ListNode* prev = NULL;
		ListNode* node = head;
		while(node && node->next)
		{
			ListNode* nextPair = node->next->next;

			// Prev
			if(prev)
				prev->next = node->next;

			// Swap
			node->next->next = node;
			node->next = nextPair;

			// Next pair
			prev = node;
			node = nextPair;
		}

		return newHead;
	}
};