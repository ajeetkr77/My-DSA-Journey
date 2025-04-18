class Solution {
public:
    string countAndSay(int n) {
        vector<string> dp(n+1);
        dp[1] = "1";

        for(int i = 2; i < n + 1; i++){
            int count = 1;
            int len = dp[i-1].length();
            string temp = "";
            for(int j = 1; j < len; j++){
                if(dp[i-1][j] == dp[i-1][j-1]){
                    count++;
                }else{
                    temp += to_string(count) + dp[i-1][j-1];
                    count = 1;
                }
            }
            temp += to_string(count) + dp[i-1][len-1]; 
            dp[i] = temp;
        }

        return dp[n];
    }
};
