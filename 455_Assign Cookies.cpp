#include <vector>
#include <algorithm>

class Solution
{

public:

	int findContentChildren(std::vector<int>& g, std::vector<int>& s)
	{
		// Sorting
		std::sort(g.begin(), g.end());
		std::sort(s.begin(), s.end());

		// Greedy
		int num = 0;
		for(int i = 0, j = 0;
			i < g.size() && j < s.size();)
		{
			if(g[i] <= s[j])
			{
				// Content
				num++;
				i++;
				j++;
			}
			else
			{
				// Bigger cookie
				j++;
			}
		}

		return num;
	}
};