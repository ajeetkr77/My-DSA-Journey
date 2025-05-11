class Solution {
public:
    int minDeletion(string s, int k) {
        int n = s.length();

        vector<int> fre(26, 0);

        for(int i = 0; i < n; i++){
            fre[s[i] - 'a']++;
        }

        int dis = 0;

        for(int i = 0; i < 26; i++){
            if(fre[i] > 0) dis++;
        }

        if(dis <= k) return 0;

        sort(fre.begin(), fre.end());

        int del = 0;

        for(int i = 0; i < 26; i++){
            if(fre[i] > 0) {
                del += fre[i];
                dis--;
            }
            if(dis <= k) return del;
        }

        return del;
    }
};
