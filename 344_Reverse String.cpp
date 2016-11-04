#include <string>

class Solution
{

public:

	std::string reverseString(std::string s)
    {
		std::string clone = std::string(s);
        char* ptrFront = &clone[0];
        char* ptrEnd = &clone[clone.size() - 1];
        while(ptrEnd >= ptrFront)
        {
            // Reach the same index
            if (ptrFront == ptrEnd)
                break;

            // Swap
            swapChar(ptrFront, ptrEnd);

            // Move pointers
            ptrFront++;
            ptrEnd--;
        }

		return clone;
    }

private:

    void swapChar(char* a, char* b)
    {
        char temp = *a;
        *a = *b;
        *b = temp;
    }
};
