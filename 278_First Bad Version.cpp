// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

// Binary search
class Solution
{

public:

	int firstBadVersion(int n)
	{
		int left = 0;
		int right = n;
		while(left < right)
		{
			int mid = left + (right - left) / 2;

			// Test mid
			if(isBadVersion(mid))
			{
				// Bad: in the left half
				right = mid;
			}
			else
			{
				// Good: in the right half
				left = mid + 1;
			}
		}

		return left;
	}
};