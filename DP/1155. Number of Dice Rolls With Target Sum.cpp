*****************************************
Recursion + Memoization

*****************************************

  class Solution {
public:
    int Mod = 1e9 + 7;
    int solve(int n, int k, int targetSum, vector<vector<int>> &t){

        if(targetSum < 0) return 0;

        if(n == 0){
            return targetSum == 0;
        }

        if(t[n][targetSum] != -1) return t[n][targetSum];

        int ways = 0;

        for(int face = 1; face <= k; face++){
            ways = (ways + solve(n-1, k, targetSum - face, t) % Mod) % Mod;
        }

        return t[n][targetSum] = ways;
    }

    int numRollsToTarget(int n, int k, int target) {
        
        vector<vector<int>> t(n+1, vector<int>(target+1, -1));

        int ans = solve(n, k, target, t);

        return ans;
    }
};

*********************************************************
Bottom Up Approach 
********************************************************

  class Solution {
public:
    int Mod = 1e9 + 7;
    
    int numRollsToTarget(int n, int k, int x) {
        
        vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
        
        dp[0][0] = 1;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= x; j++){
                
                int ways = 0;
                
                for(int face = 1; face <= k; face++){
                    
                    if(face <= j)
                        ways = (ways + dp[i-1][j-face] % Mod) % Mod;
                }
                
                dp[i][j] = ways;
            }
        }
        
        return dp[n][x];
    }
};
