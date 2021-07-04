class Solution {

public:

	int addDigits(int num)
	{
		// Find digital root
		return 1 + ((num - 1) % 9);
	}

};