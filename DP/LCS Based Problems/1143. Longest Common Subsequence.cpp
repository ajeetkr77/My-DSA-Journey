*************************************************
    Recursion + Memoization 
*************************************************
class Solution {
  public:
    int m, n;

    int t[1001][1001];
    int solve(string &s1, int i, string &s2, int j){
        
        if(i >= m || j >= n) return 0;
        
        if(t[i][j] != -1) return t[i][j];
        
        int chooseBoth = 0, chooseS1 = 0, chooseS2 = 0;
        
        if(s1[i] == s2[j]){
            chooseBoth = 1 + solve(s1, i + 1, s2, j + 1);
        }else{
            chooseS1 = solve(s1, i + 1, s2, j);
            chooseS2 = solve(s1, i, s2, j + 1);
        }
        
        return t[i][j] = max(chooseBoth, max(chooseS1, chooseS2));
    }
    
    int lcs(string &s1, string &s2) {
        // code here
        m = s1.length(), n = s2.length();
        
        memset(t, -1, sizeof(t));
        
        int ans = solve(s1, 0, s2, 0);
        
        
        
        return ans;
    }
};


*************************************************
    Bottom Up Approach
*************************************************
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();

        int n = text2.size();

        vector<vector<int>> lcs(m+1, vector<int>(n+1, 0));

        for(int i = 1; i <= m; i++){

            for(int j = 1; j <= n; j++){

                if(text1[i-1] == text2[j-1]){
                    lcs[i][j] = 1 + lcs[i-1][j-1];
                }else{
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
                }
            }
        }

        return lcs[m][n];
    }
};
