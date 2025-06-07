class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        // Code here.
        
        int n = a1.size();
        vector<int> sum1(n), sum2(n);
        
        for(int i = 0; i < n; i++){
            if(i == 0){
                sum1[i] = a1[i];
                sum2[i] = a2[i];
            }else{
                sum1[i] = sum1[i-1] + a1[i];
                sum2[i] = sum2[i-1] + a2[i];
            }
        }
        
        unordered_map<int, int> mp;
        
        mp[0] = -1;
        
        int maxLen = 0;
        
        for(int i = 0; i < n; i++){
            
            int diff = sum1[i] - sum2[i];
            
            if(mp.count(diff)){
                
                int index = mp[diff];
                maxLen = max(maxLen, i - index);
            }else{
                mp[diff] = i;
            }
        }
        
        return maxLen;
    }
};
