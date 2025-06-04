class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        // code here
        unordered_map<int, int> mp;
        
        vector<int> ans;
        
        for(int i = 0; i < a.size(); i++) mp[a[i]] = 1;
        
        for(int i = 0; i < b.size(); i++){
            if(mp.count(b[i])){
                ans.push_back(b[i]);
                mp.erase(b[i]);
            }
        }
        
        return ans;
    }
};
