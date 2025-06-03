class Solution {
  public:
    int atMost(string& s, int k){
        
        int n = s.length();
        
        int left = 0, right = 0;
        
        unordered_map<char, int> fre;
        
        int res = 0;
        
        while(right < n){
            fre[s[right]]++;
            
            if(fre[s[right]] == 1)
                k -= 1;
                
            while(k < 0){
                fre[s[left]]--;
                if(fre[s[left]] == 0){
                    k += 1;
                }
                left += 1;
            }
            
            res += right - left + 1;
            right += 1;
        }
        
        return res;
    }
    
    int countSubstr(string& s, int k) {
        // code here.
        int n = s.length();
        
        int exactlyK = atMost(s, k) - atMost(s, k-1);
        
        return exactlyK;
    }
};
