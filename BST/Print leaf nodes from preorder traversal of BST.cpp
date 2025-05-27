class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        // code here
        int n = preorder.size();
        
        stack<int> st;
        
        vector<int> leafNodes;
        
        for(int i = 0; i < n; i++){
            if(st.empty()) st.push(preorder[i]);
            else{
                
                int count = 0;
                int ans = st.top();
                while(!st.empty() && preorder[i] > st.top()){
                    count++;
                    st.pop();
                }
                st.push(preorder[i]);
                if(count >= 2) leafNodes.push_back(ans);
            }
        }
        
        leafNodes.push_back(preorder[n-1]);
        
        return leafNodes;
    }
};
