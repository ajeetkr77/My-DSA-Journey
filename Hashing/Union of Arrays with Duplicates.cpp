class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_map<int, int> mp;
        
        int count = 0;
        
        for(int i = 0; i < a.size(); i++){
            if(mp[a[i]]) continue;
            
            count++;
            mp[a[i]] = 1;
        }
        
        for(int i = 0; i < b.size(); i++){
            if(mp[b[i]]) continue;
            
            count++;
            mp[b[i]] = 1;
        }
        
        return count;
    }
};
