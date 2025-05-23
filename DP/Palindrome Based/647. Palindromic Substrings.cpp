class Solution {
public:
    int countSubstrings(string s) {

        int n = s.length();
        
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        for(int i = 0; i < n; i++) dp[i][i] = true;
        
        // Length == 2;
        
        for(int i = 0; i < n - 1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
            }
        }
        
        // Palindrome of length 
        
        for(int len = 3; len <= n; len++){
            for(int i = 0; i < n - len + 1; i++){
                int j = i + len - 1;
                
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                }
            }
        }

        // counting number of palindrome

        int count = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(dp[i][j]) count++;
            }
        }

        return count;
    }
};
