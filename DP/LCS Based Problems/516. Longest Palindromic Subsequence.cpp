class Solution {
public:
    int m;
    int t[1001][1001];
    
    int solve(string &s1, int i, string &s2, int j){
        
        if(i >= m || j >= m) return 0;
        
        if(t[i][j] != -1) return t[i][j];
        
        if(s1[i] == s2[j])
            return t[i][j] =  1 + solve(s1, i+1, s2, j+1);
        
        return t[i][j] = max(solve(s1, i, s2, j+1), solve(s1, i+1, s2, j));     
    }


    int longestPalindromeSubseq(string s) {
        string s1 = s;
        
        memset(t,-1, sizeof(t));
        
        reverse(s.begin(), s.end());
        
        m = s1.length();
        
        //cout<<s1<<" "<<s<<" ";
        
        int ans = solve(s1, 0, s, 0);
        
        return ans;
    }
};
