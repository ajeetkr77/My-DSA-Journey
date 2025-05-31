class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        
        int n = arr.size();
        
        vector<int> nextStockSpan(n), previousStockSpan(n);
        
        stack<int> st;
        
        for(int i = 0; i < n; i++){
            
            while(!st.empty() && arr[i] <= arr[st.top()])
                st.pop();
                
            if(st.empty()) previousStockSpan[i] = i + 1;
            
            else
                previousStockSpan[i] = i - st.top();
            
            st.push(i);
        }
        
        st = stack<int>();
        
        for(int i = n-1; i >= 0; i--){
            
            while(!st.empty() && arr[i] <= arr[st.top()])
                st.pop();
                
            if(st.empty()) nextStockSpan[i] = n - i;
            
            else
                nextStockSpan[i] = st.top() - i;
            
            st.push(i);
            
        }
        
        int ans = INT_MIN;
        
        for(int i = 0; i < n; i++){
            
            int count = previousStockSpan[i] + nextStockSpan[i] - 1;
            
            ans = max(ans, count * arr[i]);
            
        }
        
        return ans;
    }
};
