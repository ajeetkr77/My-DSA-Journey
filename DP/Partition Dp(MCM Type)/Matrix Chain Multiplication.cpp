class Solution {
  public:
    int t[101][101];
    int f(int i, int j, vector<int> &arr){
        
        if(i == j) return 0;
        
        if( t[i][j] != -1 ) return t[i][j];
        
        int mini = 1e9;
        
        for(int k = i; k < j; k++){
            
            int steps = (arr[i-1]*arr[k]*arr[j]) + f(i, k, arr) + f(k+1, j, arr);
            mini = min(steps, mini);
            
        }
        
        return t[i][j] = mini;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        memset(t, -1, sizeof(t));
        
        return f(1, n - 1, arr);
    }
};


**********************************************
  Tabulation Bottom Up
**********************************************
class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i = n-2; i > 0; i--){
            for(int j = i+1; j < n; j++){
                
                int mini = 1e9;
                
                for(int k = i; k < j; k++){
                    
                    int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                    mini = min(mini, steps);
                }
                
                dp[i][j] = mini;
            }
        }
        return dp[1][n-1];
    }
};
  
