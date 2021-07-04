#include <string>

class Solution
{

public:

	std::string getHint(std::string secret, std::string guess)
	{
		int numCounts[10] = { 0 };
		const int OFFSET = '0';
		int A = 0;
		int B = 0;
		for(int i = 0; i < secret.size(); i++)
		{
			char c1 = secret[i];
			char c2 = guess[i];
			if(c1 == c2)
				A++;
			else
			{
				// Secret char
				if(numCounts[c1 - OFFSET] < 0)
				{
					// Was not enough
					B++;
				}
				numCounts[c1 - OFFSET]++;

				// Guessed char
				if(numCounts[c2 - OFFSET] > 0)
					B++;
				numCounts[c2 - OFFSET]--;
			}
		}

		// Construct return string
		std::string hint = std::to_string(A) + "A" + std::to_string(B) + "B";
		return hint;
	}
};

class Solution
{

public:

	std::string getHint(std::string secret, std::string guess)
	{
		// Store the numbers contained in secret string
		int numCounts[10] = { 0 };
		const int OFFSET = '0';
		for(int i = 0; i < secret.size(); i++)
		{
			numCounts[secret[i] - OFFSET]++;
		}

		// Check
		int A = 0;
		int B = 0;
		for(int i = 0; i < guess.size(); i++)
		{
			// B
			int num = guess[i];
			if(numCounts[num - OFFSET] > 0)
				B++;

			// Guessed numbers
			numCounts[num - OFFSET]--;
		}
		for(int i = 0; i < guess.size(); i++)
		{
			// A
			int num = guess[i];
			if(num == secret[i])
			{
				A++;
				B--;
			}
		}

		// Construct return string
		std::string hint = std::to_string(A) + "A" + std::to_string(B) + "B";
		return hint;
	}
};