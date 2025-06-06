********************************************************************

[Naive Approach] Using Nested loop - O(n2) Time and O(1) Space
[Expected Approach] Sliding Window - O(n) Time and O(1) Space
[Alternate Approach] Hashing + Prefix Sum - O(n) Time and O(n) Space

**********************************************************************

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int n = arr.size();
        
        unordered_map<int, int> mp;
        
        mp[0] = 0;
        int currSum = 0;
        
        for(int i = 0; i < n; i++){
            
            currSum += arr[i];
            
            if(mp.count(currSum - target)){
                return {mp[currSum - target] + 1, i+1};
            }
            
            if(mp.count(currSum)) continue;
            
            mp[currSum] = i+1;
        }
        
        
        return {-1};
    }
};

**************************************************
  Sliding Window 
************************************************

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int n = arr.size();
        
        int currSum = 0;
        
        int s = 0, e;
        
        for(int i = 0; i < n; i++){
            
            currSum += arr[i];
            
            e = i;
            
            while(currSum > target && s < e){
                currSum -= arr[s];
                s++;
            }
            
            if(currSum == target){
                return{s+1, e+1};
            }
        }
        
        
        return {-1};
    }
};
