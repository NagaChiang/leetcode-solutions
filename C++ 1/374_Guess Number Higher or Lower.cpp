// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

// Binary search
class Solution
{

public:

	int guessNumber(int n)
	{
		int low = 1;
		int high = n;
		while(low <= high)
		{
			//int mid = (low + high) / 2; // overflow warning!
			int mid = low + (high - low) / 2; 
			int result = guess(mid);
			if(result == 0)
			{
				// Right answer
				return mid;
			}
			else if(result > 0)
			{
				// Bigger
				low = mid + 1;
			}
			else
			{
				// Smaller
				high = mid - 1;
			}
		}

		return 0;
	}
};

// Ternary search (divided by 3)
class Solution
{

public:

	int guessNumber(int n)
	{
		int low = 1;
		int high = n;
		while(low <= high)
		{
			int mid1 = low + (high - low) / 3;
			int mid2 = high - (high - low) / 3;
			int res1 = guess(mid1);
			int res2 = guess(mid2);
			if(res1 == 0)
				return mid1;
			if(res2 == 0)
				return mid2;
			else if(res1 < 0)
				high = mid1 - 1;
			else if(res2 > 0)
				low = mid2 + 1;
			else {
				low = mid1 + 1;
				high = mid2 - 1;
			}
		}

		return 0;
	}
};