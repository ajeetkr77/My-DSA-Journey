class Solution {
  public:
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int n = arr.size();
        
        int minDiv = 1;
        
        int maxDiv = *max_element(arr.begin(), arr.end());
        
        int ans;
        
        while(minDiv <= maxDiv){
            
            int midDiv = (minDiv + maxDiv) / 2;
            
            int sum = 0;
            
            for(int i = 0; i < n; i++){
                sum += ceil(arr[i] / (midDiv * 1.0));
            }
             
            if(sum <= k){
                ans = midDiv;
                maxDiv = midDiv - 1;
            }else{
                minDiv = midDiv + 1;
            }   
        }
        
        return ans;
    }
};
