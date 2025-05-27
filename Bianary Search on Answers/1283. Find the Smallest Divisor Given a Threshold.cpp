class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {

        int n = nums.size();
        
        int low = 1, high = *max_element(nums.begin(), nums.end());

        // After dividing by max we get sum = nums.size()
        // we can start with min 1 as ans will be between these 
        // low and high value;

        int ans ;

        while(low <= high){

            int mid = (low + high) / 2;

            int result = 0;

            for(int i = 0; i < n; i++){
                result += ceil(nums[i] / (mid * 1.0));
            }

            if(result <= threshold){
                ans = mid;
                high = mid - 1;
            }else
                low = mid + 1;
        }

        return ans;
    }
};
