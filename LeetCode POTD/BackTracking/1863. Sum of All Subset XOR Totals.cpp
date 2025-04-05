
********************************** Approach 1 ********************
  Using Recursion 

  class Solution {
public:
    int ans = 0;
    void findAllSubsets(vector<int>& nums, int i, int n, vector<int> &temp){
        if(i >= n) {
            int x = 0;
            for(int k = 0; k < temp.size(); k++)
                x ^= temp[k];
            ans += x;
            return;
        }

        temp.push_back(nums[i]);
        findAllSubsets(nums, i+1, n, temp);
        temp.pop_back();
        findAllSubsets(nums, i+1, n, temp);
    }

    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        findAllSubsets(nums, 0, n, temp);
        return ans;
    }
};

************************************** Approach 2 ****************************

class Solution {
public:
    int ans = 0;
    void findAllSubsets(vector<int>& nums, int i, int n, int x){
        if(i >= n) {
            ans += x;
            return;
        }
        x ^= nums[i];
        findAllSubsets(nums, i+1, n, x);
        x ^= nums[i];
        findAllSubsets(nums, i+1, n, x);
    }

    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        findAllSubsets(nums, 0, n, 0);
        return ans;
    }
};

******************************** Approach 3 **********************************

  Observation Based 
******************************************************************************
  
  class Solution {
public:

    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++) ans |= nums[i];
        ans = ans << (n-1);
        return ans;
    }
};
