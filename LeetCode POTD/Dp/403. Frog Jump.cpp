************************* Using Recursion and Memoization ***************
  Time Complexity : O(N^2)
*************************************************************************

class Solution {
public:
    map<int,int> mp;
    int dp[2001][2001];

    bool solve(int i, int k, int n, vector<int> &stones){
        if(i == n-1) return true;
        if(k == 0) return false;

        if(dp[i][k] != -1){
            return dp[i][k];
        }
        
        bool a = false, b = false, c = false;

        int pos = stones[i] + k;

        if(mp.find(pos-1) != mp.end())
            a = solve(mp[pos-1], k-1, n, stones);

        if(mp.find(pos) != mp.end())
            b = solve(mp[pos], k, n, stones);

        if(mp.find(pos+1) != mp.end())
            c = solve(mp[pos+1], k+1, n, stones);
        return dp[i][k] = (a || b || c);
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        for(int i = 0; i < n; i++) mp[stones[i]] = i;
        if(stones[1] != 1) return false;
        memset(dp, -1, sizeof(dp));
        return solve(1, 1, n, stones);
    }
};
