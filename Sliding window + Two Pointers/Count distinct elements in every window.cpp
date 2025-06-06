class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        
        int n = arr.size();
        
        unordered_map<int, int> fre;
        
        vector<int> dis;
        
        for(int i = 0; i < n; i++){
            
            fre[arr[i]]++;
            
            if(i >= k-1){
                dis.push_back(fre.size());
            
                fre[arr[i+1-k]]--;
            
                if(fre[arr[i+1-k]] == 0) fre.erase(arr[i+1-k]);
            }
        }
        
        return dis;
    }
};
