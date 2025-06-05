class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Your code here
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        
        int left = 0, right = n - 1;
        
        int count = 0;
        
        while(left < right){
            
            int sum = arr[left] + arr[right];
            
            if(sum >= target){
                right--;
            }else{
                
                count += (right - left);
                left++;
            }
            
        }
        
        return count;
    }
};
