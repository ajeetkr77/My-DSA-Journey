
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();

        vector<int> mod(n, 0);

        for(int i = 0; i < n; i++){
            if(nums[i] % modulo == k)
                mod[i] = 1;
        }

        map<int, int> mp ;
        mp[0] = 1;

        int sum = 0;

        long long result = 0;

        for(int i = 0; i < n; i++){
            sum += mod[i];

            int r1 = sum % modulo;
            int r2 = r1 - k + modulo;
            r2 %= modulo;

            if(mp.find(r2) != mp.end()){
                result += mp[r2];
            }

            mp[r1]++;
        }

        return result;
        
    }
};
