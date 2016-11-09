#include <string>
#include <unordered_map>

// 85 ms
class Solution
{

public:

	int romanToInt(std::string s)
	{
		// Dict
		std::unordered_map<char, int> mapRomanToInt = {
			{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
		};

		// Convert
		int sum = 0;
		for(int i = s.length() - 1; i >= 0; i--)
		{
			// First one
			if(i == s.length() - 1)
			{
				sum += mapRomanToInt[s[i]];
				continue;
			}

			// If roman num less than last one, substract it
			if(mapRomanToInt[s[i]] < mapRomanToInt[s[i + 1]])
				sum -= mapRomanToInt[s[i]];
			else
				sum += mapRomanToInt[s[i]];
		}

		return sum;
	}
};

// Array version
// 39 ms
class Solution
{

public:

	int romanToInt(std::string s)
	{
		// Dict
		int mapRomanToInt[100] = { 0 };
		mapRomanToInt['I'] = 1;
		mapRomanToInt['V'] = 5;
		mapRomanToInt['X'] = 10;
		mapRomanToInt['L'] = 50;
		mapRomanToInt['C'] = 100;
		mapRomanToInt['D'] = 500;
		mapRomanToInt['M'] = 1000;

		// Convert
		int sum = 0;
		for(int i = s.length() - 1; i >= 0; i--)
		{
			// First one
			if(i == s.length() - 1)
			{
				sum += mapRomanToInt[s[i]];
				continue;
			}

			// If roman num less than last one, substract it
			if(mapRomanToInt[s[i]] < mapRomanToInt[s[i + 1]])
				sum -= mapRomanToInt[s[i]];
			else
				sum += mapRomanToInt[s[i]];
		}

		return sum;
	}
};