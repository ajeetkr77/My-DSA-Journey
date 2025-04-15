class NumArray {
public:
    vector<int> segmentTree;
    int n ;
    void buildSegmentTree(int i, int l, int r, vector<int>& nums){
        if(l == r){
            segmentTree[i] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;

        buildSegmentTree(2*i + 1, l, mid, nums);
        buildSegmentTree(2*i + 2, mid + 1, r, nums);

        segmentTree[i] = segmentTree[2*i + 1] + segmentTree[2*i + 2];
    }

    int querySegmentTree(int qS, int qE, int i, int l, int r){
        if(l > qE || r < qS){
            return 0;
        }

        if(l>= qS && r <= qE){
            return segmentTree[i];
        }

        int mid = l + (r - l) / 2;

        int left = querySegmentTree(qS, qE, 2*i + 1, l , mid);
        int right = querySegmentTree(qS, qE, 2*i + 2, mid+1, r);

        return left + right;
    }

    void updateSegmentTree(int idx, int val, int i, int l, int r){
        if(l == r){
            segmentTree[i] = val;
            return;
        }

        int mid = l + (r - l) / 2;

        if(idx <= mid){
            updateSegmentTree(idx, val, 2*i + 1, l, mid);
        }else{
            updateSegmentTree(idx, val, 2*i + 2, mid + 1, r);
        }

        segmentTree[i] = segmentTree[2*i + 1] + segmentTree[2*i + 2];
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segmentTree.resize(4*n);
        buildSegmentTree(0, 0, n-1, nums);
    }
    
    void update(int index, int val) {
        updateSegmentTree(index, val, 0, 0, n-1);
    }
    
    int sumRange(int left, int right) {
        return querySegmentTree(left, right, 0, 0, n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
