class Solution {
public:
    typedef long long ll;

    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        
        ll sum = 0;
        int count = 0;

        int minLoss = INT_MAX;

        for(int num : nums){

            if((num ^ k) > num){
                sum += (num ^ k);
                count++;
            }else{
                sum += num;
            }

            minLoss = min(minLoss, abs(num - (num ^ k)));
        }

        if(count % 2 == 0) return sum;

        return sum - minLoss;
    }
};
