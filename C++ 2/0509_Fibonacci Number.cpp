class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        
        int last2 = 0;
        int last1 = 1;
        for (int i = 2; i <= n; i++) {
            int current = last1 + last2;
            last2 = last1;
            last1 = current;
        }
        
        return last1;
    }
};