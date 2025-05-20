class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int zeroPtr = 0, twoPtr = n-1;
        
        for(int i = 0; i < n; i++){
            if(arr[i] == 0){
                swap(arr[zeroPtr], arr[i]);
                zeroPtr++;
            }
        }
        
        for(int i = n -1 ; i >= 0; i--){
            if(arr[i] == 2){
                swap(arr[twoPtr], arr[i]);
                twoPtr--;
            }
        }
    }
};
