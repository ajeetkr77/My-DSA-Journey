************************************
Recursion + Memoization
************************************

  class Solution {
  public:
    int t[1002][1002];
    int solve(vector<int>& arr, int n, int prevIndex, int currIndex){
        
        if(currIndex >= n){
            return 0;
        }
        
        if(prevIndex != -1 && t[prevIndex][currIndex] != -1)
            return t[prevIndex][currIndex];
        
        int taken = 0, not_taken = 0;
        
        if(prevIndex != -1 && arr[currIndex] <= arr[prevIndex]){
            not_taken = solve(arr, n, prevIndex, currIndex + 1);
        }else{
            taken = 1 + solve(arr, n, currIndex, currIndex + 1);
            not_taken = solve(arr, n, prevIndex, currIndex + 1);
        }
        
        if(prevIndex != -1)
            t[prevIndex][currIndex] = max(taken, not_taken);
            
        return max(taken, not_taken);
    }
    
    
    int lis(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        memset(t, -1, sizeof(t));
        
        int ans = solve(arr, n, -1, 0);
        
        return ans;
    }
};


*********************************************************
DP Approach : O(n2)
*********************************************************

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        // Method 1: Time Complexity : (O(nlogn))
        // int n=nums.size();
        // vector<int>ele;
        // ele.push_back(nums[0]);
        // for(int i=1; i<n; i++){
        //     int n1=ele.size();
        //     if(nums[i]>ele[n1-1]){
        //         ele.push_back(nums[i]);
        //     }else{
        //         auto it=lower_bound(ele.begin(), ele.end(), nums[i]);
        //         *it=nums[i];
        //     }
        // }
        // int sizeOfEle = ele.size();
        // return sizeOfEle;

        // Method 2 : Time Complexity : O(n^2), Space Complexity : O(n)
        // Dynamic Programming

        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 0; i < n; i++) ans = max(ans, dp[i]);
        return ans;
    }
};
