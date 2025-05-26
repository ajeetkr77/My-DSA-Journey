*****************************************************
  Rexursion + Memoization
*****************************************************

class Solution {
  public:
    int n, maxi = 1e6;
    
    int solve(vector<int> &coins, int sum, int i, vector<vector<int>> &t){
        if(i == n){
            return (sum == 0) ? 0 : maxi;
        }
        
        if(sum < 0)
            return maxi;
        
        if(sum == 0)
            return 0;
            
        if(t[i][sum] != -1) return t[i][sum];
            
        int taken = maxi, notTaken = 0;
            
        if(sum >= coins[i]){
            taken = 1 + solve(coins, sum - coins[i], i, t);
        }
        
        notTaken = solve(coins, sum, i + 1, t);
        
        return t[i][sum] = min(taken, notTaken);
    }
    
    int minCoins(vector<int> &coins, int sum) {
        // code here
        n = coins.size();
        
        vector<vector<int>> t(n+1, vector<int>(sum+1, -1));
        
        int result = solve(coins, sum, 0, t);
        
        return (result == maxi) ? -1 : result;
    }
};

***********************************************
Bottom Up
**********************************************

  class Solution {
  public:
     int n, maxi = 1e8;
    
    // int solve(vector<int> &coins, int sum, int i, vector<vector<int>> &t){
    //     if(i == n){
    //         return (sum == 0) ? 0 : maxi;
    //     }
        
    //     if(sum < 0)
    //         return maxi;
        
    //     if(sum == 0)
    //         return 0;
            
    //     if(t[i][sum] != -1) return t[i][sum];
            
    //     int taken = maxi, notTaken = 0;
            
    //     if(sum >= coins[i]){
    //         taken = 1 + solve(coins, sum - coins[i], i, t);
    //     }
        
    //     notTaken = solve(coins, sum, i + 1, t);
        
    //     return t[i][sum] = min(taken, notTaken);
    // }
    
    int minCoins(vector<int> &coins, int sum) {
        // code here
        n = coins.size();
        
        vector<vector<int>> t(n+1, vector<int>(sum+1, 0));
        
        for(int i = 0; i < n + 1; i++) t[i][0] = 0;
        
        for(int j = 1; j <= sum; j++) t[0][j] = maxi;
        
        for(int i =1; i <= n; i++){
            for(int j = 1; j <= sum; j++){
                
                int taken = maxi, notTaken = 0;
                if(j >= coins[i-1]){
                    taken = 1 + t[i][j - coins[i-1]];
                }
                
                notTaken = t[i-1][j];
                t[i][j] = min(taken, notTaken);
            }
        }
        
        return (t[n][sum] == maxi) ? -1 : t[n][sum];
    }
};
