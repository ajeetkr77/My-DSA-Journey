class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int currSum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0;

        for(int i = 0; i < n; i++){
            currSum += nums[i];
            if(mp.find(currSum - k) != mp.end())
                count += mp[currSum - k];                                     
            mp[currSum]++;
        }
        return count;
    }
};
