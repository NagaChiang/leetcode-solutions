class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        
        return profit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int i = 0;
        while (i < prices.size() - 1) {
            while (i < prices.size() - 1 && prices[i] >= prices[i + 1]) {
                i++;
            }
            
            int valley = prices[i];
            
            while (i < prices.size() - 1 && prices[i] <= prices[i + 1]) {
                i++;
            }
            
            int peak = prices[i];
            profit += peak - valley;
        }
        
        return profit;
    }
};