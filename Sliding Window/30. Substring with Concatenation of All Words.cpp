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
*************************** Optimal Approach **********************************

  The time complexity of the given code is O(m * k) where m is the length of the string s and k is the length of each word within the words list. 
  This stems from the fact that we iterate over the string s in increments of k for loops starting at each of the first k characters.

  The space complexity is O(n * k) where n is the number of words in the given list words and k is the length of each word.

*******************************************************************************

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
       // Count the frequency of each word in 'words'.
        unordered_map<string, int> wordCount;
        for (auto& word : words) {
            ++wordCount[word];
        }

        int stringSize = s.size(), wordCountSize = words.size(), wordSize = words[0].size();
        vector<int> substrIndices;

        // Iterate over the string 's'.
        for (int i = 0; i < wordSize; ++i) {
            unordered_map<string, int> windowCount;
            int left = i, right = i;
            int totalCount = 0;

            // Slide a window over the string 's'.
            while (right + wordSize <= stringSize) {
                string currentWord = s.substr(right, wordSize);
                right += wordSize;

                // Skip the current segment if the word is not in 'words'.
                if (!wordCount.count(currentWord)) {
                    windowCount.clear();
                    left = right;
                    totalCount = 0;
                    continue;
                }

                // Update the count for the current word in the window.
                ++windowCount[currentWord];
                ++totalCount;

                // If there are more occurrences of 'currentWord' in the window than in 'words', remove from the left.
                while (windowCount[currentWord] > wordCount[currentWord]) {
                    string wordToRemove = s.substr(left, wordSize);
                    left += wordSize;
                    --windowCount[wordToRemove];
                    --totalCount;
                }

                // If the total count of words match and all words frequencies are as expected, add to result.
                if (totalCount == wordCountSize) {
                    substrIndices.push_back(left);
                }
            }
        }

        return substrIndices;
    }
};
