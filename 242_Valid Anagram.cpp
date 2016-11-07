#include <string>
#include <string.h>

class Solution
{

public:

	bool isAnagram(std::string s, std::string t)
	{
		// Different length
		if(s.length() != t.length())
			return false;

		// Count characters
		const int OFFSET = 'a';
		const int SIZE = 26;
		int charCounts_1[SIZE] = { 0 };
		int charCounts_2[SIZE] = { 0 };
		for(int i = 0; i < s.length(); i++)
		{
			charCounts_1[s[i] - OFFSET]++;
			charCounts_2[t[i] - OFFSET]++;
		}

		// Compare
		if(memcmp(charCounts_1, charCounts_2, sizeof(int) * SIZE) == 0)
			return true;
		else
			return false;
	}
};