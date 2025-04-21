class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();

        vector<long long> diffSum(n);

        diffSum[0] = differences[0];

        long long maxi = diffSum[0], mini = diffSum[0];

        for(int i = 1; i < n; i++){
            diffSum[i] = diffSum[i-1] + differences[i];

            if(maxi < diffSum[i]) maxi = diffSum[i];

            if(mini > diffSum[i]) mini = diffSum[i];
        }

        long long ans = 0; 

        for(int val = lower; val <= upper; val++){
            if( (val + mini >= lower) && (val + maxi <= upper)){
                ans++;
            }

            if(val + maxi > upper) break;
        }

        return ans;
    }
};
