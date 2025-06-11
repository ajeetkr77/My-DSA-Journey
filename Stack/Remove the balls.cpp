class Solution {
  public:
    int findLength(vector<int> &c, vector<int> &r) {
        // code here
        
        int n = c.size();
        
        stack<pair<int, int>> st;
        
        for(int i = 0; i < n; i++){
            if(st.empty()){
                st.push({c[i], r[i]});
            }else{
                
                pair<int, int> tEle = st.top();
                
                if(tEle.first == c[i] && tEle.second == r[i]){
                    st.pop();
                }
                else
                    st.push({c[i], r[i]});
            }
        }
        
        
        return st.size();
    }
};
