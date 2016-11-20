#include <algorithm>

class Solution
{

public:

	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
	{
		// Areas
		int area1 = (C - A) * (D - B);
		int area2 = (G - E) * (H - F);

		// Intersect
		int topRight_x = std::min(C, G);
		int topRight_y = std::min(D, H);
		int botLeft_x = std::max(A, E);
		int botLeft_y = std::max(B, F);
		int intersect = std::max((long)topRight_x - botLeft_x, (long)0) * std::max((long)topRight_y - botLeft_y, (long)0);

		return area1 + area2 - intersect;
	}
};