class Solution
{

public:

	int getSum(int a, int b)
	{
		// One of them is 0
		if(a == 0)
			return b;
		if(b == 0)
			return a;

		// Calculate
		int aClone = a;
		int bClone = b;
		int carry = 0;
		while(bClone != 0)
		{
			// Carry
			carry = aClone & bClone;

			// Add (without carry)
			aClone ^= bClone;

			// Move carry and assign it to b
			bClone = carry << 1;
		}

		return aClone;
	}

};