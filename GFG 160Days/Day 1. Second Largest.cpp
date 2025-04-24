class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        int maxi = INT_MIN;
        int maxi2 = INT_MIN;
        
        for(int i  = 0; i < n; i++){
            maxi = max(maxi, arr[i]);
        }
        
        for(int i  = 0; i < n; i++){
            if(arr[i] < maxi){
                maxi2 = max(maxi2, arr[i]);
            }
        }
        
        return (maxi2 == INT_MIN) ? -1 : maxi2;
    }
};
