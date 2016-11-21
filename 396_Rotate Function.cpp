#include <vector>
#include <limits>

// Math
class Solution
{

public:

	int maxRotateFunction(std::vector<int>& A)
	{
		if(A.size() == 0)
			return 0;

		// Array sum
		int arraySum = 0;
		for(int i = 0; i < A.size(); i++)
			arraySum += A[i];

		// First function sum
		int firstSum = 0;
		for(int i = 0; i < A.size(); i++)
			firstSum += i * A[i];

		// From the second one
		int max = firstSum;
		int sum = firstSum;
		for(int i = A.size() - 1; i > 0; i--)
		{
			// Add difference from last sum
			int diff = arraySum - A.size() * A[i];
			sum += diff;

			// Find max
			if(sum > max)
				max = sum;
		}

		return max;
	}
};

// Naive (Time limit exceeded)
class Solution
{

public:

	int maxRotateFunction(std::vector<int>& A)
	{
		if(A.size() == 0)
			return 0;

		// Brute
		int max = std::numeric_limits<int>().min();
		for(int i = 0; i < A.size(); i++)
		{
			// Function
			int sum = 0;
			for(int j = 0; j < A.size(); j++)
			{
				sum += j * A[(i + j) % A.size()];
			}

			// Find max
			if(sum > max)
				max = sum;
		}

		return max;
	}
};