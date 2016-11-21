#include <math.h>

class Solution
{

public:

	int findNthDigit(int n)
	{
		// Find the subset where n lies in
		int digitLength = 1;
		int digitNum = 9;
		while((long)digitLength * digitNum < n)
		{
			n -= digitLength * digitNum;
			digitLength++;
			digitNum *= 10;
		}

		// Find the number where n lies in
		int first = pow(10, digitLength - 1);
		int num = first + ((n - 1) / digitLength);

		// Get the digit from the left
		int digitFromLeft = (n - 1) % digitLength + 1;
		int digitFromRight = digitLength - digitFromLeft + 1;
		int divide = pow(10, digitFromRight - 1);
		int digit = (num / divide) % 10;

		return digit;
	}
};