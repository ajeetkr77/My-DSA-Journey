class Solution {
  public:
    string maxSubseq(string& s, int k) {
        // code here
        int n = s.length();
        
        stack<int> st;
        
        for(int i = 0; i < n; i++){
            
            while(!st.empty() && st.top() < s[i] - 'a' && k > 0){
                st.pop();
                k--;
            }
            
            st.push(s[i]-'a');
        }
        
        string ans = "";
        
        while(!st.empty()){
            ans += st.top() + 'a';
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        int len = ans.length();
        
        return ans.substr(0, len - k);;
    }
};
