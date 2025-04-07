*********************** Method 1 Recursion ***************
  class Solution {
public:
    bool check(vector<int>  &nums, int i, int n, int sum){
        if(i >= n || sum == 0){
            if(sum == 0) return true;
            return false;
        }

        bool take = check(nums, i+1, n, sum - nums[i]);
        bool not_take = check(nums, i+1, n, sum);

        return take || not_take;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int x : nums) sum += x;
        if(sum % 2 != 0) return false;
        return check(nums, 0, n, sum/2);
    }
};

********************** Method 2 Memoization ***************
  class Solution {
public:
    bool check(vector<int>  &nums, int i, int n, int sum, vector<vector<int>> &dp){
        if(i >= n || sum == 0){
            if(sum == 0) return true;
            return false;
        }
        if(dp[i][sum] != -1)
            return dp[i][sum] == 1;

        bool take = false;
        if(nums[i] <= sum)
            take = check(nums, i+1, n, sum - nums[i], dp);

        bool not_take = check(nums, i+1, n, sum, dp);

        return dp[i][sum] = take || not_take ;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int x : nums) sum += x;
        if(sum % 2 != 0) return false;
        vector<vector<int>> dp(n, vector<int>(sum/2+1, -1));
        return check(nums, 0, n, sum/2, dp);
    }
};

*************************** Method 3 *****************************

  Tabulatation / Bottom Up
*****************************************************************

class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int x : nums) sum += x;
        if(sum % 2 != 0) return false;

        sum /= 2;
        vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
        for(int i = 0; i < n; i++) dp[i][0] = true;
        if(nums[0] <= sum){
            dp[0][nums[0]] = true;
        }

        for(int ind = 1; ind < n; ind++){
            for(int j = 1; j <= sum; j++){
                bool not_taken = dp[ind-1][j];
                
                bool taken = false;
                if(nums[ind] <= j) 
                    taken = dp[ind-1][j-nums[ind]];
                
                dp[ind][j] = taken || not_taken;
            }
        }

        return dp[n-1][sum];
    }
};

*************************************** Bottom Up/ Space Optimization *****************************

class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int x : nums) sum += x;
        if(sum % 2 != 0) return false;

        sum /= 2;
        vector<bool> prev(sum+1, false);

        prev[0] = true;
        if(nums[0] <= sum) prev[nums[0]] =  true;

        for(int ind = 1; ind < n; ind++){
            vector<bool> curr(sum+1, false);
            curr[0] = true;
            for(int target = 1; target <= sum; target++){
                curr[target] = prev[target]; // not taken
                if(nums[ind] <= target)
                    curr[target] = curr[target] || prev[target - nums[ind]]; // taken
            }
            prev = curr;
        }

        return prev[sum];
    }
};
