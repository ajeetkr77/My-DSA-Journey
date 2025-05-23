class Solution {
  public:
    string longestPalindrome(string &s) {
        // code here
        int index = 0, maxLength = 1;
        
        int n = s.length();
        
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        for(int i = 0; i < n; i++) dp[i][i] = true;
        
        // Length == 2;
        
        for(int i = 0; i < n - 1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                if(maxLength < 2){
                    index = i;
                    maxLength = 2;
                }
            }
        }
        
        // Palindrome of length 
        
        for(int len = 3; len <= n; len++){
            for(int i = 0; i < n - len + 1; i++){
                int j = i + len - 1;
                
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    if(maxLength < len){
                        index = i;
                        maxLength = len;
                    }
                }
                
            }
        }
        
        
        return s.substr(index, maxLength);
    }
};
