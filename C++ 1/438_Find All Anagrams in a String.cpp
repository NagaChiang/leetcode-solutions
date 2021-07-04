#include <string>
#include <vector>
#include <string.h>

// Best
// 29 ms
class Solution
{

public:

	std::vector<int> findAnagrams(std::string s, std::string p)
	{
		// Edge cases
		if(s.size() < p.size())
			return std::vector<int>();

		if(s.size() == 0 && p.size() == 0)
		{
			std::vector<int> zero;
			zero.push_back(0);
			return zero;
		}

		// Count characters
		const int NUM_CHAR = 26;
		const int OFFSET = 'a';
		int charCounts[NUM_CHAR] = { 0 };
		for(int i = 0; i < p.size(); i++)
		{
			charCounts[p[i] - OFFSET]++;
		}

		// Check with a window
		std::vector<int> anagramIndex;
		int left = 0;
		int right = 0;
		int charNeeded = p.size();
		while(right < s.size())
		{
			// If window length too long (+1), check left and move it
			if(right - left == p.size())
			{
				if(charCounts[s[left] - OFFSET] >= 0)
					charNeeded++;

				charCounts[s[left] - OFFSET]++;
				left++;
			}

			// Check right and move it
			charCounts[s[right] - OFFSET]--;
			if(charCounts[s[right] - OFFSET] >= 0)
				charNeeded--;
			right++;

			// Found matched anagram
			if(charNeeded == 0)
				anagramIndex.push_back(left);
		}

		return anagramIndex;
	}
};

// Copy hash tables
// 1109 ms
class Solution
{

public:

	std::vector<int> findAnagrams(std::string s, std::string p)
	{
		// Edge cases
		if(s.size() < p.size())
			return std::vector<int>();

		if(s.size() == 0 && p.size() == 0)
		{
			std::vector<int> zero;
			zero.push_back(0);
			return zero;
		}

		/*if(s.size() == 0 || p.size() == 0)
		return std::vector<int>();*/

		// Count characters
		const int NUM_CHAR = 26;
		const int OFFSET = 'a';
		int charCounts[NUM_CHAR] = { 0 };
		for(int i = 0; i < p.size(); i++)
		{
			charCounts[p[i] - OFFSET]++;
		}

		// Check with a window
		std::vector<int> anagramIndex;
		for(int i = 0; i <= s.size() - p.size(); i++)
		{
			// Count the characters within the window
			int counts[NUM_CHAR];
			memcpy(counts, charCounts, NUM_CHAR * sizeof(int));
			bool isAnagram = true;
			for(int j = 0; j < p.size(); j++)
			{
				int num = --counts[s[i + j] - OFFSET];

				if(num < 0)
				{
					isAnagram = false;
					break;
				}
			}

			// Compared to the char counts of string p
			if(isAnagram)
			{
				anagramIndex.push_back(i);
			}
		}

		return anagramIndex;
	}
};

// Compare hash tables
// 1300 ms
class Solution
{

public:

	std::vector<int> findAnagrams(std::string s, std::string p)
	{
		// Edge cases
		if(s.size() < p.size())
			return std::vector<int>();

		if(s.size() == 0 && p.size() == 0)
		{
			std::vector<int> zero;
			zero.push_back(0);
			return zero;
		}

		/*if(s.size() == 0 || p.size() == 0)
			return std::vector<int>();*/

		// Count characters
		const int NUM_CHAR = 26;
		const int OFFSET = 'a';
		int charCounts[NUM_CHAR] = { 0 };
		for(int i = 0; i < p.size(); i++)
		{
			charCounts[p[i] - OFFSET]++;
		}

		// Check with a window
		std::vector<int> anagramIndex;
		for(int i = 0; i <= s.size() - p.size(); i++)
		{
			// Count the characters within the window
			int counts[NUM_CHAR] = { 0 };
			for(int j = 0; j < p.size(); j++)
			{
				counts[s[i + j] - OFFSET]++;
			}

			// Compared to the char counts of string p
			if(memcmp(counts, charCounts, NUM_CHAR * sizeof(int)) == 0)
			{
				anagramIndex.push_back(i);
			}
		}

		return anagramIndex;
	}
};