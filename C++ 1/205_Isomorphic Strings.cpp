#include <string>
#include <vector>
#include <unordered_map>

// Map characters of two strings
// 6 ms
class Solution
{

public:

	bool isIsomorphic(std::string s, std::string t)
	{
		bool isSame = true;
		char mapST[256] = { 0 };
		char mapTS[256] = { 0 };
		for(int i = 0; i < s.size(); i++)
		{
			// Look up map
			char charS = s[i];
			char charT = t[i];
			if(mapST[charS] > 0)
			{
				// Already mapped, compared to string t
				if(mapST[charS] != charT)
				{
					isSame = false;
					break;
				}
			}
			else
			{
				// Hasn't mapped in s
				if(mapTS[charT] > 0)
				{
					// ...But has mapped in t
					isSame = false;
					break;
				}

				// Map
				mapST[charS] = charT;
				mapTS[charT] = charS;
			}
		}

		return isSame;
	}
};

// Convert to pattern first
// 26 ms
class Solution
{

public:

	bool isIsomorphic(std::string s, std::string t)
	{
		std::vector<int> pattern_1 = toPattern(s);
		std::vector<int> pattern_2 = toPattern(t);

		// Compare patterns
		int isSame = true;
		for(int i = 0; i < s.size(); i++)
		{
			if(pattern_1[i] != pattern_2[i])
			{
				isSame = false;
				break;
			}
		}

		return isSame;
	}

private:

	std::vector<int> toPattern(const std::string& str)
	{
		std::vector<int> pattern;
		std::unordered_map<char, int> map;
		int charId = 1;
		for(int i = 0; i < str.size(); i++)
		{
			// Look up mapping
			int id = map[str[i]];
			if(id > 0)
			{
				// Found
				pattern.push_back(id);
			}
			else
			{
				// New char
				map[str[i]] = charId;
				pattern.push_back(charId);
				charId++;
			}
		}

		return pattern;
	}
};