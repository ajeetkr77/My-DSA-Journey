****************************** Brute Force Approach ***************************
  T. C = O(N^2 logN)
  S. C = O(N)
******************************************************************************

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length();
        int wordCount = words.size();
        int wordLen = words[0].length();
        int windowLen = wordCount * wordLen;

        sort(words.begin(), words.end());

        vector<int> index;

        for(int i = 0; i < n - windowLen + 1;  i++){
            string temp = s.substr(i, windowLen);
            //cout<<temp<<endl;
            int j = 0;
            vector<string> tempWords;
            while(j < windowLen){
                string temp1 = temp.substr(j, wordLen);
                //cout<<temp1<<endl;
                tempWords.push_back(temp1);
                j += wordLen;
            }
            sort(tempWords.begin(), tempWords.end());
            if(words == tempWords) index.push_back(i);
        }
        return index;
    }
};
