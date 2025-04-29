class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement = INT_MIN;

        int n = nums.size();

        for(int i = 0; i < n; i++) maxElement = max(maxElement, nums[i]);

        long long result = 0;

        int i = 0, j = 0, count = 0;

        while( j < n ){

            if(nums[j] == maxElement) count++;

            while(count >= k){
                result += n - j;
                if(nums[i] == maxElement) count--;
                i++;
            }
            
            j++;
        }

        return result;
    }
};
