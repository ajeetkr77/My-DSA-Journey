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

***************************************************
Approach - 2 

***************************************************

    class Solution {
public:
    typedef long long ll;

    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        
        ll sum = 0;
        int n = nums.size();
        
        vector<int> profit;

        for(int num : nums){
            sum += num;
            profit.push_back((num ^ k) - num);
        }

        sort(profit.rbegin(), profit.rend());

        // chooosing profitable pairs as we can choose only in pairs 

        for(int i = 0; i < n  - 1; i+=2){
            if(profit[i] + profit[i+1] > 0) sum += profit[i] + profit[i+1];
        }

        return sum;
    }
};
