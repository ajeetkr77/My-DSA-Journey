class Solution {
  public:
  
    int countSmallerToMid(vector<vector<int>> &matrix, int n, int mid){
        
        int row = 0, col = n-1;
        int count = 0;
        
        while(row < n && col >= 0){
            if(matrix[row][col] <= mid){
                count += col + 1;
                row += 1;
            }else{
                col -= 1;
            }
        }
        
        return count;
    }
    
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
        int n = matrix.size();
        
        int low = matrix[0][0], high = matrix[n-1][n-1];
        
        int ans = 0;
        
        while(low <= high){
            
            int mid = (low + high) / 2;
            
            int count = countSmallerToMid(matrix, n, mid);
            
            if(count < k){
                low = mid + 1;
            }else{
                ans = mid;
                high = mid - 1;
            }
        }
        
        return ans;
    }
};
