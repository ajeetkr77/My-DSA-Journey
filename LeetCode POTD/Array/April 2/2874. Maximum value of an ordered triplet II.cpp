********************* Better Approach ****************************
                    Time Complexity : O(N)
                    Space Complexity : O(N)
******************************************************************
  
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<int> rightMax(n, 0);

        for(int i = n-2; i >= 0; i--){
            rightMax[i] = max(rightMax[i+1], nums[i+1]);
        }

        int leftMax = nums[0];

        for(int i  = 1; i < n-1; i++){
            ans = max(ans, (long long)(leftMax - nums[i])*rightMax[i]);
            leftMax = max(leftMax, nums[i]);
        }

        return ans;    
    }
};

********************* Optimal Approach ****************************
                    Time Complexity : O(N)
                    Space Complexity : O(1)
******************************************************************
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<int> rightMax(n, 0);

        for(int i = n-2; i >= 0; i--){
            rightMax[i] = max(rightMax[i+1], nums[i+1]);
        }

        int leftMax = nums[0];

        for(int i  = 1; i < n-1; i++){
            ans = max(ans, (long long)(leftMax - nums[i])*rightMax[i]);
            leftMax = max(leftMax, nums[i]);
        }

        return ans;
    }
};
