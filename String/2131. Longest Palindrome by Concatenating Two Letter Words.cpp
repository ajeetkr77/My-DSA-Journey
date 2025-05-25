class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        map<string, int> mp;

        int n = words.size();

        int equal = 0, len = 0;

        for(int i = 0; i < n; i++){
            string temp = words[i];
            reverse(temp.begin(), temp.end());
            if(mp[temp]){
                len += 4;
                mp[temp]--;
            }else
                mp[words[i]]++;
        }

        for(auto p : mp){
            if(p.second && p.first[0] == p.first[1])
                equal = 1; 
        }

        return (equal) ? len + 2 : len;
    }
};
