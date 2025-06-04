class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        
        unordered_map<int, int> mp;
        
        mp[0] = 1;
        
        int currXor = 0;
        
        long ans = 0;
        
        for(int i = 0; i < n; i++){
            
            currXor ^= arr[i];
            
            if(mp.count(currXor ^ k)) ans += mp[currXor ^ k];
            
            mp[currXor]++;
        }
        
        return ans;
    }
};
