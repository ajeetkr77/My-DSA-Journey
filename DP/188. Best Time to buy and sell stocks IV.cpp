****************** Using Recursion **********************
class Solution {
public:
    int profit(vector<int>& prices, int i, int n, int cap, int buy){
        if(i == n || cap == 0) return 0;
        if(buy){
            int take = -prices[i] + profit(prices, i+1, n, cap, 0);
            int not_take = profit(prices, i+1, n, cap, 1);
            return max(take, not_take);
        }
        int sell = prices[i] + profit(prices, i+1, n, cap - 1, 1);
        int not_sell = profit(prices, i+1, n, cap, 0);

        return max(sell, not_sell);
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        return profit(prices, 0, n, k,1);
    }
};

************************ Memoization *********************************
class Solution {
public:
    int profit(vector<int>& prices, int i, int n, int cap, int buy, vector<vector<vector<int>>> &dp){
        if(i == n || cap == 0) return 0;
        if(dp[i][buy][cap] != -1) return dp[i][buy][cap];
        if(buy){
            int take = -prices[i] + profit(prices, i+1, n, cap, 0, dp);
            int not_take = profit(prices, i+1, n, cap, 1, dp);
            return dp[i][buy][cap] = max(take, not_take);
        }
        int sell = prices[i] + profit(prices, i+1, n, cap - 1, 1, dp);
        int not_sell = profit(prices, i+1, n, cap, 0, dp);

        return dp[i][buy][cap] = max(sell, not_sell);
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return profit(prices, 0, n, k, 1, dp);
    }
};
************************ Tabulation **********************************

***********************  Tabulation + Space Optimization ************
