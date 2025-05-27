class Solution {
public:
    bool possible(vector<int>& bloomDay, int day, int m, int k){
        int count = 0;
        int bouque = 0;
        int n = bloomDay.size();

        for(int i = 0; i < n; i++){
            if(bloomDay[i] <= day){
                count++;
            }else{
                bouque += (count / k);
                count = 0;
            }
        }
        bouque += (count / k);
        
        return (bouque >= m);
    }


    int minDays(vector<int>& bloomDay, int m, int k) {

        long long n = bloomDay.size();

        long long mul = m * 1LL * k * 1LL;

        if(n < mul) return -1;
        
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int ans ;

        while(low <= high){
            int mid = (low + high) / 2;

            if(possible(bloomDay, mid, m, k)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;
    }
};
