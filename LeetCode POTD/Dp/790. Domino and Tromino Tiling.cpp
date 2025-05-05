************************************************
  Recursion + Memoization
************************************************

class Solution {
public:
    int mod = 1e9 + 7;
    int t[10001];

    int solve(int n){
        if(n == 1 || n == 2)
            return n;
        if(n == 3)
            return 5;
        
        if(t[n] != -1) return t[n];

        return t[n] = (2 * solve( n - 1 ) % mod + solve( n - 3 ) % mod) % mod;
    }

    int numTilings(int n) {
        memset(t, -1, sizeof(t));

        return solve(n);
    }
};


**************************************************
Bottom Up : 
**************************************************

  class Solution {
public:
    int mod = 1e9 + 7;
    int numTilings(int n) {
        
        vector<int> dp(n+1, 0);

        if(n == 1 || n ==2) return n;

        if(n == 3) return 5;

        if(n > 3){
            dp[1] = 1, dp[2] = 2, dp[3] = 5;
        }

        for(int i = 4; i <= n; i++) dp[i] = (2 * dp[i-1] % mod + dp[i-3] % mod) % mod;

        return dp[n];
    }
};
