************************ Better Approach **********************
  T.C = O(N)
  S.C = O(N)
***************************************************************

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMin(n, INT_MAX);
        vector<int> rightMin(n, INT_MAX);

        int ans = INT_MAX;

        for(int i = 1; i < n; i++){
            int val = min(leftMin[i-1], nums[i-1]);
            if(val < nums[i])
                leftMin[i] = val;
        }

        for(int i = n-2; i >= 0; i--){
            int val = min(rightMin[i+1], nums[i+1]);
            if(val < nums[i])
                rightMin[i] = val;
        }

        // for(int i = 0; i < n; i++) cout<<leftMin[i]<<" ";
        // cout<<endl;
        // for(int i = 0; i < n; i++) cout<<rightMin[i]<<" ";
        // cout<<endl;

        for(int i = 1; i < n-1; i++){
            if(leftMin[i] != INT_MAX && rightMin[i] != INT_MAX)
                ans = min(ans, nums[i] + leftMin[i] + rightMin[i]);
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};

*********************************** Optimal Solution ********************
  
