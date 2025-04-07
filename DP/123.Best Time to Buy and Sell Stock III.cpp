******************************* Memoization ******************************

class Solution {
public:
    int profit(vector<int> &prices, int buy, int cap, int n, int i,  vector<vector<vector<int>>>& dp){
        if(cap <= 0 || i >= n) return 0;
        
        if(dp[i][buy][cap] != -1) return dp[i][buy][cap];

        if(buy){
            int take = -prices[i] + profit(prices, 0, cap, n, i+1, dp);
            int not_take = profit(prices, 1, cap, n, i+1, dp);
            return dp[i][buy][cap] = max (take, not_take);
        }
        
        int sell = prices[i] + profit(prices, 1, cap-1, n, i+1, dp);
        int not_sell = profit(prices, 0, cap, n, i+1, dp);
        return dp[i][buy][cap] = max(sell, not_sell);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
        return profit(prices, 1, 2, n, 0,dp);
    }
};

******************************** Tabulation ***************************************
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));

        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 1; cap <= 2; cap++){
                    if(buy){
                        int take = -prices[i] +  dp[i+1][0][cap];
                        int not_take = dp[i+1][1][cap];
                        dp[i][buy][cap] = max (take, not_take);
                    }else{
                        int sell = prices[i] + dp[i+1][1][cap-1];
                        int not_sell = dp[i+1][0][cap];
                        dp[i][buy][cap] = max(sell, not_sell);
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};

*********************** Tabulation + Space Optimization ********************************************
  class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int>(3,0));

        for(int i = n-1; i >= 0; i--){
            vector<vector<int>> curr(2, vector<int>(3,0));
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 1; cap <= 2; cap++){
                    if(buy){
                        int take = -prices[i] +  after[0][cap];
                        int not_take = after[1][cap];
                        curr[buy][cap] = max (take, not_take);
                    }else{
                        int sell = prices[i] + after[1][cap-1];
                        int not_sell = after[0][cap];
                        curr[buy][cap] = max(sell, not_sell);
                    }
                }
            }
            after = curr;
        }

        return after[1][2];
    }
};
