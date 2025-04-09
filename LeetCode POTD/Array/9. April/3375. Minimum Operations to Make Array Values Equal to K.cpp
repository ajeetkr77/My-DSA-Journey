
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int minOp = 0;
        
        int Min = INT_MAX;
        for(int i = 0; i < n; i++) Min = min(Min, nums[i]);
        if( Min < k ) return -1;

        set<int> st;
        for(int i = 0; i < n; i++) st.insert(nums[i]);

        if( k < Min ) return st.size();
        return st.size() - 1;
    }
};

**************** Space Optimization *********************

  class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int minOp = 0;
        
        int Min = INT_MAX;
        for(int i = 0; i < n; i++) Min = min(Min, nums[i]);
        if( Min < k ) return -1;

        unordered_set<int> st(nums.begin(), nums.end());
        //for(int i = 0; i < n; i++) st.insert(nums[i]);

        if( k < Min ) return st.size();
        return st.size() - 1;
    }
};
