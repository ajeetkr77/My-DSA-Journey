class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        
        int l = 1 , r = m*n;

        int ans = 0;

        // Binary Search on Answers

        while(l <= r){

            int mid = l + (r - l) / 2;

            int count = 0;

            for(int i = 1; i <= m; i++){
                
                count += min( mid / i, n);

            }

            if(count >= k){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }

        }

        return ans;

    }
};
