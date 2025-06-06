class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int n = s.length();
        
        unordered_map<char, int> fre;
        
        int maxLen = 1;
        
        int start = 0;
        
        for(int e = 0; e < n; e++){
            
            while(fre.count(s[e])){
                fre.erase(s[start]);
                start++;
            }
            
            fre[s[e]] = 1;
            
            maxLen = max(maxLen, e - start + 1);
        }
        
        return maxLen;
    }
};
