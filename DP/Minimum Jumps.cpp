*********************************************
  Recursion + Memoization
*********************************************

class Solution {
  public:
    int n, maxi = 1e9;
    int t[10001];
    int solve(vector<int>& arr, int i){
        if(i >= n - 1) return 0;
        
        if(t[i] != -1) return t[i];
        
        int steps = arr[i];
        int ways = maxi;
        
        for(int j = 1; j <= steps; j++){
            int way = 1 + solve(arr, i + j);
            ways = min(ways, way);
        }
        
        return t[i] = ways;
    }
    
    int minJumps(vector<int>& arr) {
        // code here
        n = arr.size();
        memset(t, -1, sizeof(t));
        
        int result = solve(arr, 0);
        
        return (result == maxi) ? -1 : result;
    }
};

*******************************************
Bottom up
******************************************
class Solution {
  public:
       int n, maxi = 1e9;
    // int t[10001];
    // int solve(vector<int>& arr, int i){
    //     if(i >= n - 1) return 0;
        
    //     if(t[i] != -1) return t[i];
        
    //     int steps = arr[i];
    //     int ways = maxi;
        
    //     for(int j = 1; j <= steps; j++){
    //         int way = 1 + solve(arr, i + j);
    //         ways = min(ways, way);
    //     }
        
    //     return t[i] = ways;
    // }
    
    int minJumps(vector<int>& arr) {
        // code here
        n = arr.size();
        vector<int> dp(n, maxi);
        
        dp[0] =  0;
        
        for(int i = 0; i < n; i++){
            
            int steps = arr[i];
            for(int j = 1; j <= steps; j++){
                if(i + j >= n)
                    break;
                dp[i+j] = min(dp[i+j], 1 + dp[i]);
            }
        }
        
        return (dp[n-1] == maxi) ? -1 : dp[n-1];
    }
};
