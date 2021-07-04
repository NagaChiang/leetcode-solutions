#include <string>

// Note: Array is way faster than map and unordered_map.

class Solution
{

public:

	bool canConstruct(std::string ransomNote, std::string magazine)
	{
		// Count every char in magazine
		const int OFFSET = 'a';
		int charCounts[26] = { 0 };
		for(int i = 0; i < magazine.length(); i++)
		{
			charCounts[magazine[i] - OFFSET]++;
		}

		// Reduce the amount of each character used
		bool isPossible = true;
		for(int i = 0; i < ransomNote.length(); i++)
		{
			char c = ransomNote[i];
			int count = --charCounts[c - OFFSET];

			// Use too much
			if(count < 0)
			{
				isPossible = false;
				break;
			}
		}

		return isPossible;
	}
};