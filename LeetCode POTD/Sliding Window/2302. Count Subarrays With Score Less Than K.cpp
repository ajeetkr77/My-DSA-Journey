class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();

        long long ans = 0;

        int i = 0, j = 0;
        long long sum = 0, len = 1;

        while(j < n){

            sum += nums[j];

            len = j - i + 1;

            while(sum * len >= k){
                sum -= nums[i];
                i++;
                len--;
            }
            ans += j - i + 1;
            j++;
        }

        return ans;
    }
};
