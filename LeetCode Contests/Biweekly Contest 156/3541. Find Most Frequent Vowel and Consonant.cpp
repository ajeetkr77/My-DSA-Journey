class Solution {
public:
    int maxFreqSum(string s) {
        map<char, int> fre;

        for(int i = 0; i < s.length(); i++){
            fre[s[i]]++;
        }

        int maxV = 0, maxC = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                maxV = max(maxV, fre[s[i]]);
            else
                maxC = max(maxC, fre[s[i]]);
        }

        return maxV + maxC;
    }
};
