class Solution {
  public:
    int countSubstring(string &s) {
        // code here
        vector<int> fre(26, 0);
        
        for(char ch : s) fre[ch - 'a']++;
        
        int ans = 0; 
        
        for(int i = 0; i < 26; i++){
            if(fre[i] > 0){
                
                int extra = (fre[i] < 2) ? 0 : (fre[i] * (fre[i] - 1)) / 2;
                
                ans += extra + fre[i];
                
            }
        }
        
        return ans;
    }
};
