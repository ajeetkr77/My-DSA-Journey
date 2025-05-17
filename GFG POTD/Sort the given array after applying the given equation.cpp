class Solution {
  public:
    int quadFn(int x, int A, int B, int C){
        
        int fx = ((A * x * x) + (B * x) + C);
        return fx;
    }
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        // code here
        int n = arr.size();
        vector<int> modArr(n);
        
        for(int i = 0; i < n; i++){
            modArr[i] = quadFn(arr[i], A, B, C);
        }
        
        sort(modArr.begin(), modArr.end());
        return modArr;
    }
};
