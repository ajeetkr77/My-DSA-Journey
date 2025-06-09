class Solution {
  public:
    void Reverse(stack<int> &st) {
        
        if(st.empty()) return;
        
        int x = st.top();
        st.pop();
        
        Reverse(st);
        
        vector<int> temp;
        
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        
        st.push(x);
        
        for(int i = temp.size() - 1;  i >= 0; i--) st.push(temp[i]);
    }
};
