class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        int result = 0;

        map<int, int> mp;
        mp[0] = 1;
        int sum = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];

            int r1 = sum % k;
            r1 += k;

            r1 %= k;
            
            if(mp.find(r1) != mp.end()){
                result += mp[r1];
            }

            mp[r1]++;
        }

        return result;
    }
};
