
***************************** Using Recursion ********************************
  Time Limit Exceeded
**********************************************************************
class Solution {
public:
    long long solve(int i, int n, vector<vector<int>>& q){
        if(i >= n) return 0;
      
        long long taken = q[i][0] + solve(i+1+q[i][1], n, q);
        long long notTaken = solve(i+1, n, q);

        return max(taken, notTaken);
    }
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        return solve (0, n , q, );
    }
};


************************************ Using Memoization ****************************
  
class Solution {
public:
    long long solve(int i, int n, vector<vector<int>>& q, vector<long long> &t){
        if(i >= n) return 0;

        if(t[i] != -1) return t[i];

        long long taken = q[i][0] + solve(i+1+q[i][1], n, q, t);
        long long notTaken = solve(i+1, n, q, t);

        return t[i] = max(taken, notTaken);
    }
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        vector<long long> t(n,-1);
        return solve (0, n , q, t);
    }
};

*************************************** Dynamic Programming *************************
Time Complexity : O(N)
Space Complexity : O(N)
***********************************************************************************
class Solution {
public:
    
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        if(n == 1)
            return q[0][0];

        vector<long long> dp(200001, 0);
        // dp[i] = maximum points earn by solving questions from i to n-1;
        for(int i = n-1; i >= 0; i--){
            // taken = q[i][0] + dp[i + 1 + q[i][1]]
            // not taken = dp [i + 1]
            dp[i] = max( dp[i+1], q[i][0] + dp[i + 1 + q[i][1]] );
        }
        return dp[0];
    }
};
