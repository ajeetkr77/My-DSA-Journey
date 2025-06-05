class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        vector<int> finalAns;
        
        if(n == 1) return finalAns;
        
        int minAbsDiff = INT_MAX, maxAbsDiff = INT_MIN;
        
        int left = 0, right = n - 1;
        
        while(left < right){
            
            int sum = arr[left] + arr[right];
            
            if(minAbsDiff > abs(sum - target)){
                
                minAbsDiff = abs(sum - target);
                vector<int> ans;
                ans.push_back(min(arr[left], arr[right]));
                ans.push_back(max(arr[left], arr[right]));
                finalAns = ans;
                maxAbsDiff = max(maxAbsDiff, abs(arr[left] - arr[right]));
            }
            
            if(minAbsDiff == abs(sum - target)){
                
                if(abs(arr[left] - arr[right]) > maxAbsDiff){
                    vector<int> ans;
                    ans.push_back(min(arr[left], arr[right]));
                    ans.push_back(max(arr[left], arr[right]));
                    
                    finalAns = ans;
                    
                    maxAbsDiff = abs(arr[left] - arr[right]);
                }
            }
            
            if(sum > target){
                right--;
            }
            
            else if(sum < target){
                left++;
            }
            else{
                left++;
                right--;
            }
        }
        
        return finalAns;
        
    }
};
