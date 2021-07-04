#include <string>

class Solution
{

public:

	int longestPalindrome(std::string s)
	{
		// Count characters
		const int SIZE = 52;
		int charCounts[SIZE] = { 0 };
		for(int i = 0; i < s.length(); i++)
		{
			charCounts[alphabetToIndex(s[i])]++;
		}

		// Count odds and pairs
		int hasOdd = false;
		int numPair = 0;
		for(int i = 0; i < SIZE; i++)
		{
			int count = charCounts[i];

			if(count > 0)
			{
				// Pair
				numPair += count / 2;

				// Odd
				if(count % 2 != 0)
					hasOdd = true;
			}
		}

		// Calculate palindromes
		int num = numPair * 2 + (hasOdd > 0 ? 1 : 0);
		return num;
	}

private:

	int alphabetToIndex(char c)
	{
		int index = -1;

		// Upper case (65 ~ 90)
		if(c >= 65 && c <= 90)
		{
			index = c - 'A';
		}

		// Lower case (97 ~ 122)
		else if(c >= 97 && c <= 122)
		{
			index = c - 'a' + 26;
		}

		return index;
	}
};