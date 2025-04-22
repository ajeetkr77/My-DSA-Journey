class Solution {
public:
    const int Mod = 1000000000 + 7;
    int solve(int start, int len, int n, int maxValue, vector<vector<int>> &dp){
        if(len == 1) return 1;

        if(dp[start][len] != -1) return dp[start][len];

        int count = 0;

        for(int val = start * 2; val <= maxValue; val += start){
            count += solve(val, len - 1, n, maxValue, dp);
            count %= Mod;
        }

        return dp[start][len] = count;
    }

    int idealArrays(int n, int maxValue) {
        
        int ans = 0;
        // Precompute C(n, k) using Pascal's triangle
        vector<vector<int>> comb(n + 1, vector<int>(15)); // only up to k = 14 needed
        for (int i = 0; i <= n; i++) {
            comb[i][0] = 1;
            for (int j = 1; j <= min(i, 14); j++) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % Mod;
            }
        }


        // Memoization table: memo[val][len] = number of sequences of length `len` starting from `val`
        vector<vector<int>> dp(maxValue + 1, vector<int>(15, -1));
        // n= 4, k = 3      {1,2,4}, 1,3,6
        long long total = 0;
        for (int start = 1; start <= maxValue; start++) {
            for (int len = 1; len <= 14 && len <= n; len++) {
                long long ways = (solve(start, len, n, maxValue, dp)) % Mod;
                total = (total + ((ways * comb[n - 1][len - 1]) % Mod) )% Mod;
            }
        }

        return (int) total;
    }
};
