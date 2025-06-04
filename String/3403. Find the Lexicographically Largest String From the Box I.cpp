class Solution {
public:
    string answerString(string word, int numFriends) {
        
        int n = word.length();
        int maxLen = n + 1 - numFriends;

        if(numFriends == 1) return word;

        string result="";

        
        for(int i = 0; i < n; i++){
            int possibleLen = min(maxLen, n - i);
            string temp = word.substr(i, possibleLen);
            result = max(result, temp);
        } 
        
        return result;
    }
};
