class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // strategy is to arrange nums into 
        // smallest, 2nd smallest ......bigger
        // taking difference of adjacents and taking its minimum
        // will be answer

        int ans = INT_MAX;
        for(int i = 0; i < nums.size() - 1; i++){
            ans = min(nums[i+1] - nums[i], ans);
        }
        return ans;
    }
};
