// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        vector<vector<string>> ans;
        
        unordered_map<string, int> mp;
        
        int n = arr.size();
        
        int trackIndex = 0;
        
        for(int i = 0; i < n; i++){
            
            string temp = arr[i];
            
            sort(temp.begin(), temp.end());
            
            if(mp.count(temp)){
                int index = mp[temp];
                
                ans[index].push_back(arr[i]);
            }else{
                vector<string> temp1 = {arr[i]};
                
                ans.push_back(temp1);
                
                mp[temp] = trackIndex;
                trackIndex++;
            }
    
        }
        
        return ans;
    }
};
