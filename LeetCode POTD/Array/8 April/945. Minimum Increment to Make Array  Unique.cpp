
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int minOp = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] <= nums[i-1]){
                minOp += (nums[i-1] - nums[i] + 1);
                nums[i] += nums[i-1] - nums[i] + 1;
            }
        }
        for(int i = 0; i < n; i++) cout<<nums[i]<<" ";
        return minOp;
    }
};
