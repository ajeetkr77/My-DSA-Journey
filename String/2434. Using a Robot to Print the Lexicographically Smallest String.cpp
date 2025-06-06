class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();

        // map<char, int> mp;

        // for(int i = 0; i < n; i++){
        //     mp[s[i]] = i;
        // }

        // string ans = "";

        // int startIndex = 0;

        // for(auto it: mp){
        //     int index = it.second;

        //     if(index >= startIndex){
        //         string part = s.substr(startIndex, index - startIndex + 1);
        //         reverse(part.begin(), part.end());
        //         ans += part;
        //         startIndex = index + 1;
        //     }

        //     if(startIndex == n)
        //         return ans;
        // }

        // return ans;

        vector<char> minCharRight(n);

        minCharRight[n-1] = s[n-1];

        string t = "", paper = "";

        for(int i = n - 2; i >= 0; i--){
            minCharRight[i] = min(s[i], minCharRight[i+1]);
        }

        int i = 0;

        while(i < n){

            t += s[i];

            char minChar = (i+1 == n) ? s[i] : minCharRight[i+1];

            while(!t.empty() && t.back() <= minChar){
                paper += t.back();
                t.pop_back();
            }

            i++;
        }

        while(!t.empty()){
            paper += t.back();
            t.pop_back();
        }

        return paper;
    }
};
