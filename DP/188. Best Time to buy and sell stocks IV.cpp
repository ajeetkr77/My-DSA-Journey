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
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 1; cap <= k; cap++){
                    if(buy){
                        int take = -prices[i] + dp[i+1][!buy][cap];
                        int not_take = dp[i+1][buy][cap];
                        dp[i][buy][cap] = max(take, not_take);
                    }else{
                        int sell = prices[i] + dp[i+1][!buy][cap-1];
                        int not_sell =  dp[i+1][buy][cap];
                        dp[i][buy][cap] = max(sell, not_sell);
                    }
                }
            }
        }
        return dp[0][1][k];
    }
};
***********************  Tabulation + Space Optimization ************
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int>(k+1, 0));

        for(int i = n-1; i >= 0; i--){
            vector<vector<int>> curr(2, vector<int>(k+1, 0));
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 1; cap <= k; cap++){
                    if(buy){
                        int take = -prices[i] + after[!buy][cap];
                        int not_take = after[buy][cap];
                        curr[buy][cap] = max(take, not_take);
                    }else{
                        int sell = prices[i] + after[!buy][cap-1];
                        int not_sell =  after[buy][cap];
                        curr[buy][cap] = max(sell, not_sell);
                    }
                }
            }
            after = curr;
        }
        return after[1][k];
    }
};
