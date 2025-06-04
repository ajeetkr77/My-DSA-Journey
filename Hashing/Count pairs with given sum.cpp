class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
        int n = arr.size();
        
        int countPairs = 0;
        
        unordered_map<int, int> fre;
        
        for(int i = 0; i < n; i++){
            if(fre.count(target - arr[i]))
                countPairs += fre[target-arr[i]];
            
            fre[arr[i]]++;
        }
        
        return countPairs;
    }
};
