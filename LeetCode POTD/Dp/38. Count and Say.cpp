**********************************************
Time Complexity : O(N^2)
Space Complexity : O(N)
********************************************
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


**********************************************
Time Complexity : O(N^2)
Space Complexity : Constant Space 
********************************************

class Solution {
public:
    string countAndSay(int n) {   
        string prev = "1";

        for(int i = 2; i < n + 1; i++){
            int count = 1;
            int len = prev.length();
            string curr = "";
            for(int j = 1; j < len; j++){
                if(prev[j] == prev[j-1]){
                    count++;
                }else{
                    curr += to_string(count) + prev[j-1];
                    count = 1;
                }
            }
            curr += to_string(count) + prev[len-1]; 
            prev = curr;
        }

        return prev;
    }
};
