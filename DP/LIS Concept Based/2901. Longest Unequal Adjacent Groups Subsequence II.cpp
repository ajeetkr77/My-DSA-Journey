class Solution {
public:
    bool isHamming(string a, string b){
        if(a.length() != b.length()) return false;

        int diff = 0;

        for(int i = 0; i < a.length(); i++){
            if(a[i] != b[i]) diff++;
            if(diff > 1) return false;
        }

        if(diff != 1) return false;
        return true;
    }


    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = groups.size();

        vector<int> dp(n, 1), parent(n);

        for(int i = 0; i < n; i++) parent[i] = i;

        for(int i = 1; i < n; i++){
            for(int j = i - 1; j >= 0; j--){
                if(groups[i] != groups[j] && isHamming(words[i], words[j]) && dp[i] < 1 + dp[j]){
                    dp[i] = 1 + dp[j];
                    parent[i] = j;
                }
            }
        }

        int index = 0, maxi = dp[0];

        for(int i = 1; i < n; i++){
            if(maxi < dp[i]){
                maxi = dp[i];
                index = i;
            }
        } 

        vector<string> ans;

        while(parent[index] != index){
            ans.push_back(words[index]);
            index = parent[index];
        }

        ans.push_back(words[index]);

        reverse(ans.begin(), ans.end());

        return ans;

    }
};
