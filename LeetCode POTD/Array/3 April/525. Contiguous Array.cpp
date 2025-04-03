*************************** Brute Force Approach ***************************
  class Solution {
public:
    bool check(int i, int j, vector<int>& nums){
        int count0 = 0, count1 = 0;
        for(int k = i; k <= j; k++){
            if(nums[k] == 0) count0++;
            else
                count1++;
        }
        if(count0 == count1)
            return true;
        return false;
    }

    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(check(i, j, nums)){
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        
        return maxLen;
    }
};

****************************** Optimal Approach *****************************
T.C = O(N)
S.C = O(N)
*****************************************************************************
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;

        int currSum = 0;
        for(int i = 0; i < n; i++){
            currSum = (nums[i] == 0) ? currSum - 1 : currSum + 1;
            if(mp.find(currSum) != mp.end()){
                maxLen = max(maxLen, i - mp[currSum]);
            }else
                mp[currSum] = i;
        }

        return maxLen;
    }
};
