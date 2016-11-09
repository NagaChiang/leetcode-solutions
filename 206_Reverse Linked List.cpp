#include <string.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// Iterative
// 6 ms
class Solution
{

public:

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

// Recursive
// 6 ms
class Solution
{

public:

	ListNode* reverseList(ListNode* head)
	{
		if(head == NULL || head->next == NULL)
			return head;

		ListNode* reversed = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return reversed;
	}
};