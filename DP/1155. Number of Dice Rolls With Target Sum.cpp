*****************************************
Recursion + Memoization

*****************************************

  class Solution {
public:
    int Mod = 1e9 + 7;
    int solve(int n, int k, int targetSum, vector<vector<int>> &t){

        if(targetSum < 0) return 0;

        if(n == 0){
            return targetSum == 0;
        }

        if(t[n][targetSum] != -1) return t[n][targetSum];

        int ways = 0;

        for(int face = 1; face <= k; face++){
            ways = (ways + solve(n-1, k, targetSum - face, t) % Mod) % Mod;
        }

        return t[n][targetSum] = ways;
    }

    int numRollsToTarget(int n, int k, int target) {
        
        vector<vector<int>> t(n+1, vector<int>(target+1, -1));

        int ans = solve(n, k, target, t);

        return ans;
    }
};
