#include <string>

class Solution
{

public:

	char findTheDifference(std::string s, std::string t)
	{
		// Sum of XOR = the different one char
		char sum = 0;
		for(int i = 0; i < s.length(); i++)
			sum ^= s[i];
		for(int i = 0; i < t.length(); i++)
			sum ^= t[i];

		return sum;
	}

};