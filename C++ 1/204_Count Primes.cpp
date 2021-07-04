#include <vector>

// Sieve of Eratosthenes
class Solution
{

public:

	int countPrimes(int n)
	{
		// Mark all the non-primes
		std::vector<bool> isPrime = std::vector<bool>(n, true)
		for(int i = 2; i * i < n; i++)
		{
			if(!isPrime[i])
				continue;

			for(int j = i * i; j < n; j += i)
				isPrime[j] = false;
		}

		// Count primes
		int count = 0;
		for(int i = 2; i < n; i++)
		{
			if(isPrime[i])
				count++;
		}

		return count;
	}
};