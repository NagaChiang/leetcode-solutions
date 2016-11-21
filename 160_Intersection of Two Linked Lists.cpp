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

	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		if(!headA || !headB)
			return NULL;

		// Find the node they meet
		ListNode* nodeA = headA;
		ListNode* nodeB = headB;
		ListNode* end = NULL;
		while(nodeA != nodeB)
		{
			// A
			if(nodeA->next)
			{
				nodeA = nodeA->next;
			}
			else
			{
				// Check end
				if(end == NULL)
				{
					// Keep end
					end = nodeA;
				}
				else
				{
					// Compared to end
					if(nodeA != end)
					{
						// No intersection
						nodeA = NULL;
						break;
					}
				}

				// Redirect to B
				nodeA = headB;
			}

			// B
			if(nodeB->next)
			{
				nodeB = nodeB->next;
			}
			else
			{
				// Check end
				if(end == NULL)
				{
					// Keep end
					end = nodeB;
				}
				else
				{
					// Compared to end
					if(nodeB != end)
					{
						// No intersection
						nodeA = NULL;
						break;
					}
				}

				// Redirect to A
				nodeB = headA;
			}
		}

		return nodeA;
	}
};