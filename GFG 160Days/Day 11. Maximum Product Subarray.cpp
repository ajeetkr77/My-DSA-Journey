class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        int n = arr.size();
        
        int prefixMul = 1, suffixMul = 1, maxProduct = INT_MIN;
        
        for(int i = 0; i < n; i++){
            
            prefixMul *= arr[i];
            maxProduct = max(maxProduct, prefixMul);
            
            if(prefixMul == 0) prefixMul = 1;
        }
        
        for(int i = n-1; i >= 0; i--){
            
            suffixMul *= arr[i];
            maxProduct = max(maxProduct, suffixMul);
            
            if(suffixMul== 0) suffixMul = 1;
        }
        
        return maxProduct;
    }
};

