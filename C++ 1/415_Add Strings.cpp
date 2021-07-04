#include <string>

// +: 6 ms
// insert(): 3 ms
class Solution
{

public:

	std::string addStrings(std::string num1, std::string num2)
	{
		// Adder
		const int OFFSET = 48;
		std::string strSum = "";
		for(int i = num1.length() - 1, j = num2.length() - 1, carry = 0;
			i >= 0 || j >= 0 || carry > 0;
			i--, j--)
		{
			// Get digits
			int digit1 = 0;
			int digit2 = 0;
			if(i >= 0)
				digit1 = num1[i] - OFFSET;
			if(j >= 0)
				digit2 = num2[j] - OFFSET;

			// Add
			int sum = digit1 + digit2 + carry;
			char charDigit = (sum % 10) + OFFSET;
			carry = sum / 10;
			strSum.insert(0, 1, charDigit);
		}

		return strSum;
	}
};