#include <string>

class Solution
{

public:

	std::string reverseVowels(std::string s)
	{
		char* ptrFront = &s[0];
		char* ptrEnd = &s[s.length() - 1];
		while(ptrEnd > ptrFront)
		{
			// Both are vowels
			if(isVowel(*ptrFront) && isVowel(*ptrEnd))
			{
				// Swap
				char temp = *ptrFront;
				*ptrFront = *ptrEnd;
				*ptrEnd = temp;

				// Move pointers
				ptrFront++;
				ptrEnd--;
			}
			else
			{
				// Move pointers
				if(!isVowel(*ptrFront))
					ptrFront++;
				if(!isVowel(*ptrEnd))
					ptrEnd--;
			}
		}

		return s;
	}

private:

	bool isVowel(char c)
	{
		const int NUM_VOWEL = 10;
		char vowels[NUM_VOWEL] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
		bool is = false;
		for(int i = 0; i < NUM_VOWEL; i++)
		{
			if(c == vowels[i])
			{
				is = true;
				break;
			}
		}

		return is;
	}
};