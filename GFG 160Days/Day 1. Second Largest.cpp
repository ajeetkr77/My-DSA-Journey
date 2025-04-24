**********************************************
  Better Approach : 2 Times Search 
**********************************************

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

*************************************************
Optimal Approach : 1 Time Search
*************************************************

  class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        int maxi = max(arr[0], arr[1]);
        int maxi2 = min(arr[0], arr[1]);
        
        for(int i  = 2; i < n; i++){
            if(arr[i] > maxi){
                maxi2 = maxi;
                maxi = arr[i];
            }else if(arr[i] > maxi2 && arr[i] != maxi){
                maxi2 = arr[i];
            }
        }
        
        return (maxi2 == maxi) ? -1 : maxi2;
    }
};
