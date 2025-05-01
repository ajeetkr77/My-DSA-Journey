************************************************

  Minimize the Heights I

***********************************************

  
class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        
        int ans = arr[n-1] - arr[0]; // k == 0 
        
        int smallest = arr[0] + k;
        int largest = arr[n-1] - k;
        
        int mi , ma;
        
        for(int i = 0; i < n-1; i++){
            
            mi = min(smallest, arr[i+1] - k);
            ma = max(largest, arr[i] + k);
            
            ans = min(ans, ma - mi);
        }
        
        return ans;
        
    }
};
