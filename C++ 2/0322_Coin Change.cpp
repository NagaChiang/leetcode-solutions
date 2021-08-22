// DP
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int initValue = INT_MAX - 1;
        vector<int> map(amount + 1, initValue);
        map[0] = 0;
        for (int i = 0; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i) {
                    map[i] = min(map[i], map[i - coin] + 1);
                }
            }
        }
        
        return map[amount] != initValue ? map[amount] : -1;
    }
};

// Memorization
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> map(amount + 1, -2);
        map[0] = 0;
        for (int coin : coins) {
            if (coin >= map.size()) {
                continue;
            }
            
            map[coin] = 1;
        }
        
        return getMinCoinChange(coins, amount, map);
    }
    
private:
    int getMinCoinChange(vector<int>& coins, int amount, vector<int>& map) {
        if (amount < 0) {
            return -1;
        }
        
        if (map[amount] >= -1) {
            return map[amount];
        }
        
        int minChange = -1;
        for (int coin : coins) {
            int change = getMinCoinChange(coins, amount - coin, map);
            if (change >= 0) {
                if (minChange >= 0) {
                    minChange = min(minChange, change);
                } else {
                    minChange = change;
                }
            }
        }
        
        if (minChange >= 0) {
            map[amount] = minChange + 1;
        } else {
            map[amount] = -1;
        }
        
        return map[amount];
    }
};