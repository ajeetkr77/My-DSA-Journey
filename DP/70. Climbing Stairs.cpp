*************************** Recursion ********************************

Time Complexity Summary:
Without Memoization (Pure Recursion): O(2^n)
Why Is It O(2^n)?
Recursive Tree Structure:

Each call to climbStairs(n) results in two more recursive calls:

climbStairs(n - 1)

climbStairs(n - 2)

This forms a binary recursion tree, where each node splits into two branches.

With Memoization: O(n) (because each subproblem is solved only once)

  ********************* Memoization (top down) ******************

  class Solution {
public:
    int dp[46];
    Solution(){
        memset(dp, -1, sizeof(dp));
        dp[0] = 1, dp[1] = 1; 
    }
    
    int climbStairs(int n) {
        if(dp[n] != -1) return dp[n];
        return dp[n] = climbStairs(n-1) + climbStairs(n-2);
    }
};

****************** Bottom Up *******************
  
