**********************************************
  Recursion + Memoization (Top Down)
*********************************************

class Solution {
  public:
    int t[1001][1001];
    
    int solve(int W, vector<int> &val, vector<int> &wt, int n){
        if(W == 0 || n == 0) return 0;
        
        if(t[n][W] != -1) return t[n][W];
        
        if(wt[n-1] <= W){
            return t[n][W] = max(solve(W, val, wt, n - 1), val[n-1] +
            solve(W - wt[n-1], val, wt, n - 1));
        }
        
        return t[n][W] = solve(W, val, wt, n - 1);
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        
        memset(t, -1, sizeof(t));
        
        int maxValue = solve(W, val, wt, n);
        
        return maxValue;
    }
};

************************************************
                Bottom Up
************************************************

  class Solution {
  public:
    
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        
        vector<vector<int>> dp(n+1, vector<int>(W+1));
        
        for(int i = 0; i < n + 1; i++){
            for(int j = 0; j < W + 1; j++){
                
                if(i == 0 || j == 0) dp[i][j] = 0;
                
                if(i > 0 && wt[i-1] <= j){
                    dp[i][j] = max(dp[i-1][j],  val[i-1] + dp[i-1][j-wt[i-1]]);
                }
                
                if(i > 0 && wt[i-1] > j)
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][W];
    }
};
