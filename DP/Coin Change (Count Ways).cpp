***********************************************
Recursion + Memoization 
**********************************************

  class Solution {
  public:
    int n;
    int t[1001][1001];
    int solve(vector<int>& coins, int sum, int i){
        if(i == n){
            return sum == 0;
        }
        
        if(sum == 0) return 1;
        
        if(t[i][sum] != -1) return t[i][sum];
        
        int taken = 0, notTaken = 0;
        
        if(sum >= coins[i])
            taken = solve(coins, sum - coins[i], i);
        notTaken = solve(coins, sum, i+1);
        
        return t[i][sum] = taken + notTaken;
    }
    int count(vector<int>& coins, int sum) {
        // code here.
        n = coins.size();
        memset(t, -1, sizeof(t));
        return solve(coins, sum, 0);
    }
};

****************************************************
Bottom Up
****************************************************

  class Solution {
  public:
    // int n;
    // int t[1001][1001];
    // int solve(vector<int>& coins, int sum, int i){
    //     if(i == n){
    //         return sum == 0;
    //     }
        
    //     if(sum == 0) return 1;
        
    //     if(t[i][sum] != -1) return t[i][sum];
        
    //     int taken = 0, notTaken = 0;
        
    //     if(sum >= coins[i])
    //         taken = solve(coins, sum - coins[i], i);
    //     notTaken = solve(coins, sum, i+1);
        
    //     return t[i][sum] = taken + notTaken;
    // }
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        
        for(int i = 0; i < n + 1; i++){
            dp[i][0] = 1;
        }
        
        for(int j = 1; j <= sum; j++) dp[0][j] = 0;
        
        for(int i = 1; i < n + 1; i++){
            for(int j = 1;  j <= sum; j++){
                
                if(j >= coins[i-1])
                    dp[i][j] = dp[i][j-coins[i-1]];
                
                dp[i][j] += dp[i-1][j];
            }
        }
        
        return dp[n][sum];
    }
};
