#include <string.h>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{

public:

	void deleteNode(ListNode* node)
	{
		ListNode* nextNode = node->next;
		node->val = node->next->val;
		node->next = node->next->next;
		free(nextNode);
	}
};

// Memory copy
class Solution
{

public:

	void deleteNode(ListNode* node)
	{
		ListNode* nextNode = node->next;
		memcpy(node, node->next, sizeof(ListNode));
		free(nextNode);
	}
};