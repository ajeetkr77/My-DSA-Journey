class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        
        int profit = 0;
        
        int stock = prices[0];
        
        for(int i = 1; i < n; i++){
            if(prices[i] > stock)
                profit += (prices[i] - stock);
            stock = prices[i];
        }
        return profit;
    }
};

