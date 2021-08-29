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

// DP
// At the end of the day:
// 0: Have stock
// 1: No stock
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> profits(prices.size(), vector<int>(2));
        profits[0][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            profits[i][0] = max(profits[i - 1][0], profits[i - 1][1] - prices[i]); // Bought before or buy today
            profits[i][1] = max(profits[i - 1][1], profits[i - 1][0] + prices[i]); // No stock before or sell today
        }
        
        return profits.back()[1];
    }
};