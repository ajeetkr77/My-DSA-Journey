***************************************************
  Time Complexity: O(len1 * len2 * len3)
  Memoization
***************************************************

class Solution {
  public:
  
    int t[101][101][101];
  
    int lcs(string& s1, string& s2, string& s3, int i, int j, int k){
        if(i == 0 || j == 0 || k == 0) 
            return 0;
            
        if(t[i][j][k] != -1) return t[i][j][k];
            
        if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1])
            return t[i][j][k] = 1 + lcs(s1, s2, s3, i-1, j -1, k-1);
        
        int x = lcs(s1, s2, s3, i - 1, j, k);
        
        int y = lcs(s1, s2, s3, i, j - 1, k);
        
        int z = lcs(s1, s2, s3, i, j, k - 1);
        
        return t[i][j][k] = max(x, max(y, z));
    }
    
    
    int lcsOf3(string& s1, string& s2, string& s3) {
        
        memset(t, -1, sizeof(t));
        // Code here
        
        int result = lcs(s1, s2, s3, s1.length(), s2.length(), s3.length());
        
        return result;
    }
};

**************************************************
  Time Complexity : O(len1 * len2 * len3)
  Bottom Up Approach
**************************************************

class Solution {
  public:
  
    int lcsOf3(string& s1, string& s2, string& s3) {
        
        // Code here
        
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        
        int dp[len1+1][len2+1][len3+1];
        
        for(int i = 0; i <= len1; i++){
            for(int j = 0; j <= len2; j++){
                for(int k = 0; k <= len3; k++){
                    if(i == 0 || j == 0 || k == 0)
                        dp[i][j][k] = 0;
                    
                    else if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1])
                        dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                    else
                        dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
                }
            }
        }
        
        
        return dp[len1][len2][len3];
    }
};


