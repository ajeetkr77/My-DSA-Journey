class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int partition = 1;
        int minEle = nums[0];

        for(int i = 1; i < n; i++){

            if(nums[i] - minEle <= k) continue;

            partition++;
            minEle = nums[i];
        }

        return partition;
    }
};
