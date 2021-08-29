// At the end of the day:
// 0: Have stock
// 1: No stock, in cooldown
// 2: No stock, not in cooldown
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> profits(prices.size(), vector<int>(3));
        profits[0][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            profits[i][0] = max(profits[i - 1][0], profits[i - 1][2] - prices[i]); // Bought before or buy today
            profits[i][1] = profits[i - 1][0] + prices[i]; // Sell today
            profits[i][2] = max(profits[i - 1][1], profits[i - 1][2]); // No transaction today
        }
        
        return max(profits.back()[1], profits.back()[2]);
    }
};