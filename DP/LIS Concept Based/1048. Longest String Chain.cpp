class Solution {
public:
    static bool myCompare(string &word1, string &word2){
        return word1.length() < word2.length();
    }
    
    bool checkPredecessor(string word1, string word2){
        
        if(word1.length() != word2.length() + 1) return false;
        //cout<<word1<<" "<<word2<<" ";
        
        int i = 0, j = 0;
        
        while(i < word1.length() && j < word2.length()){
            if(word1[i] == word2[j]){
                j++;
            }
            i++;
        }
        
        //cout<<j<<endl;
        if(j == word2.length()) return true;
        
        return false;
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        
        sort(words.begin(), words.end(), myCompare);
        
        // for(int i = 0; i < n; i++) cout<<words[i]<<" ";
        
        // cout<<endl;
        
        vector<int> dp(n, 1);
        int maxi = 1; 
        
        for(int i = 1; i < n; i++){
            
            for(int j = 0; j < i; j++){
                
                if(checkPredecessor(words[i], words[j]) && dp[i] < 1 + dp[j]){
                    dp[i] = 1 + dp[j];
                    //cout<<words[i]<<" "<<words[j]<<endl;
                }
                
            }
            //cout<<dp[i]<<" ";
            maxi = max(maxi, dp[i]);
        }
        //cout<<endl;
        
        return maxi;
    }
};
