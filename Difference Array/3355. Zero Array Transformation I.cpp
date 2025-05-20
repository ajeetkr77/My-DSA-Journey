class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int> diff(n, 0);

        int q = queries.size();

        for(int i = 0; i < q; i++){
            int L = queries[i][0];
            int R = queries[i][1];

            diff[L] += 1;

            if(R + 1 < n) diff[R+1] -= 1;
        }

        // calculating resulting array or prefix sum from diff

        for(int i = 1; i < n; i++) diff[i] += diff[i-1];

        for(int i = 0; i < n; i++){
            if(diff[i] < nums[i]) return false;
        }

        return true;
    }
};
