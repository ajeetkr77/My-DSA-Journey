********************************** Recursion + Memoization ***********************
  With memoization: Time complexity reduces to O(n) because each subproblem is solved only once.

Without memoization: Time complexity is O(2ⁿ) due to redundant computations.

****************************************************************************

class Solution {
public:
    int find(vector<int>& nums, int n, int i, vector<int>& dp){
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int take = nums[i] + find(nums, n, i+2,dp);
        int not_take = find(nums, n, i+1,dp);

        return dp[i] = max(take, not_take); 
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return find(nums, n, 0,dp);
    }
};

******************** Bottom Up / Tabulation *****************
  T C = O(N)
  S C = O(N)
*************************************************************

class Solution {
public:
   
    int rob(vector<int>& nums) {
        

        int n = nums.size();
        vector<int> dp(n+2, 0);
        for(int i = n-1; i >= 0; i--){
            dp[i] = max(dp[i+1], nums[i] + dp[i+2]);
        }
        return dp[0];
    }
};
