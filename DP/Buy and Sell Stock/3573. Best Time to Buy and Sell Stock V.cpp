***********************************************
  Recursion + Memoization 
***********************************************

class Solution {
public:
    int n;
    long long t[1001][501][3];
    long long buySell(vector<int>& prices, int k, int i, int status){
        if(k == 0) return 0;

        if(i == n - 1){
            if(status == 0) return 0;

            if(status == 1) return prices[i];

            return -prices[i];
        }

        if(t[i][k][status] != -1) return t[i][k][status];

        vector<long long> profit(5, INT_MIN);

        profit[2] =  buySell(prices, k, i+1, status);

        if(status == 0){
            profit[0] = -prices[i] + buySell(prices, k, i+1, 1);
            profit[1] =  prices[i] + buySell(prices, k, i+1, 2);
        }

        else if(status == 1){
            profit[3] =   prices[i] + buySell(prices, k - 1, i + 1, 0);
        }

        else if(status == 2){
            profit[4] =  -prices[i] + buySell(prices, k - 1, i + 1, 0);
        }

        return t[i][k][status] = *max_element(profit.begin(), profit.end());
    }
    long long maximumProfit(vector<int>& prices, int k) {

        n = prices.size();

        memset(t, -1, sizeof(t));
        
        long long ans = buySell(prices, k, 0, 0);

        return ans;
    }
};

**********************************************
Bottom Up
**********************************************

  
