class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int n = s.length();
        map<char, int> mp;
        for(int i = 0; i < n; i++){
            mp[s[i]] = i;
        }
    
        int i = 0;
        while(i < n){
            int start = i;
            int max_index = mp[s[i]];
            while(i < max_index){
                max_index = max(max_index, mp[s[i]]);
                i++;
            }
            i++;
            ans.push_back(max_index - start + 1);
        }

        return ans;
    }
};
