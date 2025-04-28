class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        int n = arr.size();
        int index = -1;
        
        for(int i = n-2; i >= 0; i--){
            if(arr[i] < arr[i+1]){
                index = i;
                break;
            }
        }
        
        if(index == -1){
            reverse(arr.begin(), arr.end());
            return;
        }
        
        int nextIndex = -1;
        
        for(int i = index + 1; i < n; i++){
            if(arr[i] > arr[index]){
                if(nextIndex == -1) nextIndex = i;
                else{
                    if(arr[i] < arr[nextIndex])
                        nextIndex = i;
                }
            }
        }
        
        //cout<<arr[index]<<" "<<arr[nextIndex];
        swap(arr[index], arr[nextIndex]);
        
        reverse(arr.begin() + index + 1, arr.end());
        
    }
};
