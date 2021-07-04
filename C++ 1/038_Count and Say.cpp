#include <string>

class Solution
{

public:

	std::string countAndSay(int n)
	{
		if(n <= 0)
			return "";

		// Construct sequence
		std::string lastSay = "1";
		for(int i = 2; i <= n; i++)
		{
			// Convert to say string
			std::string say;
			char lastDigit = lastSay[0];
			int count = 1;
			for(int j = 1; j < lastSay.size(); j++)
			{
				// Get the digit
				char digit = lastSay[j];

				// Compared with last digit
				if(digit != lastDigit)
				{
					// Push last digit to the front of string
					say.append(std::to_string(count) + lastDigit);

					// Count for new digit
					lastDigit = digit;
					count = 1;
				}
				else
				{
					// Count
					count++;
				}
			}

			// Push the rest to the front of string
			say.append(std::to_string(count) + lastDigit);

			// New lastSay
			lastSay = say;
		}

		return lastSay;
	}
};