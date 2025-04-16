class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        long long goodSubarrays = 0;

        unordered_map<int, int> mp;

        int pairs = 0;

        int i = 0, j = 0;

        while(j < n){

            pairs += mp[nums[j]];
            mp[nums[j]]++;

            while(pairs >= k){
                goodSubarrays += n - j;
                mp[nums[i]] --;
                pairs -= mp[nums[i]];
                i++;
            }
            j++;
        }

        return goodSubarrays;
    }
};
