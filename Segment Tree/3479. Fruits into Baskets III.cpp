
class Solution {
public:
    vector<int> segmentTree;
    int n;

    void buildSegmentTree(int i, int l, int r, vector<int>& baskets){
        if(l == r){
            segmentTree[i] = baskets[l];
            return;
        }

        int mid = l + (r - l) / 2; 

        buildSegmentTree(2*i + 1, l, mid, baskets);
        buildSegmentTree(2*i + 2, mid + 1, r, baskets);

        segmentTree[i] = max(segmentTree[2*i + 1], segmentTree[2*i + 2]);
    }

    int search(int i, int l, int r, int val){
        if( segmentTree[i] < val ) return -1;

        if(l == r){
            segmentTree[i] = -1;
            return l;
        }

        int mid = l + (r - l) / 2;
        int pos;

        if(val <= segmentTree[2*i + 1]){
            pos = search(2*i + 1, l, mid, val);
        }else
            pos = search(2*i + 2, mid + 1, r, val);

        segmentTree[i] = max(segmentTree[2*i + 1], segmentTree[2*i + 2]);

        return pos;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int fruit = fruits.size();
        int basket = baskets.size();

        int unplaced = 0;
        n = basket;

        segmentTree.resize(4*n);

        buildSegmentTree(0, 0, n-1, baskets);

        for(int i = 0; i < n; i++){
            if(search(0, 0, n-1, fruits[i]) == -1) unplaced++;
        }
        return unplaced;
    }
};
