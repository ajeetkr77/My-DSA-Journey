class Solution {
  public:
    int minDeletions(string s) {
        // code here
        string text1 = s;
        int len = s.length();
        reverse(s.begin(), s.end());
        
        string text2 = s;
        
        
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

        return len - lcs[m][n];
    }
};
