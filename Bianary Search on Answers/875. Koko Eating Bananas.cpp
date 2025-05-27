class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1 , high = *max_element(piles.begin(), piles.end());
        int n = piles.size();

        int ans;

        while(low <= high){
            
            int mid = (low + high) / 2;

            long long result = 0;

            for(int i = 0; i < n; i++){
                result += ceil(piles[i] / (mid * 1.0));
            }

            if(result <= h){
                ans = mid;
                high = mid - 1;
            }else 
                low = mid + 1;
        }

        return ans;
    }
};
