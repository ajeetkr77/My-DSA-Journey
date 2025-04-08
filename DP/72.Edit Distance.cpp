
******************* Recursion ******************************

  class Solution {
public:
    int find(string word1, int i, int m, string word2, int j, int n){
        if(i == m) return n - j;
        if(j == n) return m - i;
        if(word1[i] != word2[j]){
            int ins = 1 + find(word1, i, m, word2, j+1, n);
            int del = 1 + find(word1, i+1, m, word2, j, n);
            int rep = 1 + find(word1, i+1, m, word2, j+1, n);
            return min(ins, min(del, rep));
        }
        return find(word1, i+1, m, word2, j+1, n);
    }

    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        return find(word1, 0, m, word2, 0, n);
    }
};

******************** Memoization ****************************
class Solution {
public:
    int find(string word1, int i, int m, string word2, int j, int n, vector<vector<int>> &dp){
        if(i == m) return n - j;
        if(j == n) return m - i;
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] != word2[j]){
            int ins = 1 + find(word1, i, m, word2, j+1, n, dp);
            int del = 1 + find(word1, i+1, m, word2, j, n, dp);
            int rep = 1 + find(word1, i+1, m, word2, j+1, n, dp);
            return dp[i][j] = min(ins, min(del, rep));
        }
        return dp[i][j] = find(word1, i+1, m, word2, j+1, n, dp);
    }

    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return find(word1, 0, m, word2, 0, n,dp);
    }
};

*************************** Tabulation *******************************
  class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
       //return find(word1, 0, m, word2, 0, n,dp);

        for(int j = 0;  j <= n; j++){
            dp[m][j] = n-j;
        }

        for(int i = 0;  i <= m; i++){
            dp[i][n] = m-i;
        }

        for(int i = m - 1; i >= 0; i--){
            for(int j = n -1; j >= 0; j--){
                 if(word1[i] != word2[j]){
                    int ins = 1 + dp[i][j+1];
                    int del = 1 + dp[i+1][j];
                    int rep = 1 + dp[i+1][j+1];
                    dp[i][j] = min(ins, min(del, rep));
                }else
                    dp[i][j] = dp[i+1][j+1];
            }
        }
        return dp[0][0];
    }
};
