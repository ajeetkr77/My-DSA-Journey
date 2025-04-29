class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int profit = 0;
        
        int n = prices.size();
        
        int maxEle = prices[n-1];
        
        for(int i = n - 2; i >= 0; i--){
            
            if(prices[i] < maxEle){
                profit = max(profit, maxEle - prices[i]);
            }
            
            maxEle = max(maxEle, prices[i]);
        }
        
        return profit;
    }
};
