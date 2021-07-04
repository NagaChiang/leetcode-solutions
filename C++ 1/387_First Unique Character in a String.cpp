#include <string>

class Solution
{

public:

	int firstUniqChar(std::string s)
	{
		// Count characters
		const int OFFSET = 'a';
		int charCounts[26] = { 0 };
		for(int i = 0; i < s.length(); i++)
		{
			charCounts[s[i] - OFFSET]++;
		}
		
		// Find the first unique index
		int indexUnique = -1;
		for(int i = 0; i < s.length(); i++)
		{
			if(charCounts[s[i] - OFFSET] < 2)
			{
				indexUnique = i;
				break;
			}
		}

		return indexUnique;
	}
};