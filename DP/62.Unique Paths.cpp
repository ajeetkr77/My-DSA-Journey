********************************

  Memoization 

class Solution {
public:
    vector<vector<int>> dp;
    Solution(){
        dp.resize(101, vector<int> (101, -1));
    }

    int uniquePaths(int m, int n) {
        if(m < 0 || n < 0) return 0;

        if(m == 1 && n == 1) return 1;

        if(dp[m][n] != -1) return dp[m][n];

        int up = uniquePaths(m-1, n);

        int left = uniquePaths(m, n-1);

        return dp[m][n] = up + left;
    }
};
