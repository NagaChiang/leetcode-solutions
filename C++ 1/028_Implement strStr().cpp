#include <string>
#include <vector>

// Knuth–Morris–Pratt algorithm
// 6 ms, second
class Solution
{

public:

	int strStr(std::string haystack, std::string needle)
	{
		if(needle.length() == 0)
			return 0;
		if(haystack.length() == 0)
			return -1;

		// Preprocessing
		std::vector<int> kmp = std::vector<int>(needle.length() + 1, -1);
		for(int i = 1; i < needle.length() + 1; i++)
		{
			int pos = kmp[i - 1];
			while(pos != -1 && needle[pos] != needle[i - 1])
				pos = kmp[pos];
			kmp[i] = pos + 1;
		}

		// Searching for needle
		int found = -1;
		int indexHay = 0;
		int indexNeedle = 0;
		while(indexHay < haystack.length())
		{
			while(indexNeedle != -1 && (indexNeedle == needle.length() || needle[indexNeedle] != haystack[indexHay]))
				indexNeedle = kmp[indexNeedle];
			indexHay++;
			indexNeedle++;

			if(indexNeedle == needle.length())
			{
				found = indexHay - needle.length();
				break;
			}
		}

		return found;
	}
};