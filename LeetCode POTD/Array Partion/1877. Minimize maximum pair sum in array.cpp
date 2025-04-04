
// LeetCode 1877 : https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = nums[0] + nums[n-1];
        for(int i = 1;  i < n/2; i++) ans = max(ans, nums[i] + nums[n-1-i]);
        return ans;
    }
};
