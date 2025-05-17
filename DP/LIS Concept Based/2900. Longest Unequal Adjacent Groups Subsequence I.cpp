class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        
        int n = groups.size();

        vector<int> dp(n, 1), parent(n);

        for(int i = 0; i < n; i++) parent[i] = i;

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){

                if(groups[i] != groups[j] && dp[i] < 1 + dp[j]){
                    parent[i] = j;
                    dp[i] = 1 + dp[j];
                }
            }
        }

        vector<string> ans;

        int index = 0, maxi = dp[0];

        for(int i = 1; i < n; i++){
            if(maxi < dp[i]){
                maxi = dp[i];
                index = i;
            }
        }

        while(parent[index] != index){
            ans.push_back(words[index]);
            index = parent[index];
        }

        ans.push_back(words[index]);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

***********************************************************
    Time Complexity: O(n)
***********************************************************
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        
        int n = groups.size();

        vector<string> ans;

        for(int i = 0; i < n; i++){
            if(i == 0 || groups[i] != groups[i-1]){
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};
