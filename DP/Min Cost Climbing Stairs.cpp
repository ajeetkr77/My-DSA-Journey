**************************************
  Recursion + Memoization : O(N)
*************************************


class Solution {
  public:
    int n;
    int t[100001];
    int solve(vector<int>& ncost, int index){
        
        if(index >= n) return 0;
        
        if(t[index] != -1) return t[index];
        
        int nextStepCost = ncost[index] + solve(ncost, index + 1);
        int next2StepCost = ncost[index] + solve(ncost, index + 2);
        
        return t[index] = min(nextStepCost, next2StepCost);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        vector<int> ncost;
        ncost = cost;
        ncost.push_back(0);
        n = cost.size();
        memset(t, -1, sizeof(t));
        int maxi1 = solve(ncost, 0);
        memset(t, -1, sizeof(t));
        int maxi2 = solve(ncost, 1);
        
        return min(maxi1, maxi2);
        
    }
};


**********************************************
  Bottom Up 
**********************************************

  class Solution {
  public:
    
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        vector<int> ncost;
        int n;
        ncost = cost;
        ncost.push_back(0);
        n = ncost.size();
        
        vector<int> dp(n), dp1(n);
        
        dp[0] = ncost[0];
       
        for(int i = 1; i < n; i++){
            
            if(i == 1){
                dp[1] = ncost[1];
            }
            else
                dp[i] = ncost[i] + min(dp[i-1], dp[i-2]);
        }
        
        dp1[1] = ncost[1];
        
        
        for(int i = 2; i < n; i++){
            if(i == 2){
                dp1[2] = ncost[2] + dp1[1];
            }
            else
                dp1[i] = ncost[i] + min(dp1[i-1], dp1[i-2]);
        }
        
        
        // for(int i = 0; i < n; i++) cout<<dp[i]<<" ";
        // cout<<endl;
        
        // for(int i = 0; i < n; i++) cout<<dp1[i]<<" ";
        // cout<<endl;
        
        
        return min(dp[n-1], dp1[n-1]);
        
    }
};
