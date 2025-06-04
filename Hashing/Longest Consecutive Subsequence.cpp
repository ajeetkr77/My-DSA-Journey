class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        
        unordered_map<int, int> mp;
        
        for(int i = 0; i < n; i++){
            mp[arr[i]] = 1;
        }
        
        unordered_map<int, int> vis;
        
        int maxLen = 1;
        
        for(int i = 0; i < n; i++){
            
            int len = 0;
            
            if(!vis[arr[i]]){
                int x = arr[i];
                
                while(mp[x]){
                    vis[x] = 1;
                    len++;
                    x++;
                }
                
                x = arr[i];
                x--;
                while(mp[x]){
                    vis[x] = 1;
                    len++;
                    x--;
                }
                
                maxLen = max(maxLen, len);
            }
        }
        
        return maxLen;
    }
};
