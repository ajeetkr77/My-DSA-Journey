********************************************
  O(nlogn)
  2 pointers
********************************************

class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        
        int i = 0, j = n - 1;
        
        while(i < j){
            
            if(arr[i] + arr[j] == target)
                return true;
            
            else if(arr[i] + arr[j] > target)
                j--;
            else 
                i++;
        }
        
        return false;
    }
};

********************************************
  O(nlogn)
  Hashing
********************************************

  class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        
        int n = arr.size();
        
        unordered_map<int, int> mp;
        
        for(int i = 0; i < n; i++){
            if(mp.count(target - arr[i]))
                return true;
                
            mp[arr[i]] = 1;
        }
        
        return false;
    }
};
