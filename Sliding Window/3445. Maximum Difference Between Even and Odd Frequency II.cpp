**********************************************
          Brute Force O(n^3)
**********************************************

  class Solution {
public:
    int findDiff(string &s, int start, int end){
        vector<int> fre(5, 0);

        for(int i = start; i <= end; i++) fre[s[i] - '0']++;

        int oddFre = INT_MIN, evenFre = INT_MAX;

        for(int i = 0; i < 5; i++){
            if(fre[i] > 0){
                if(fre[i] % 2)  
                    oddFre = max(oddFre, fre[i]);

                else
                    evenFre = min(evenFre, fre[i]);
            }
        }

        if(oddFre != INT_MIN && evenFre != INT_MAX) return oddFre - evenFre;

        return INT_MIN;
    }

    int maxDifference(string s, int k) {
        
        int n = s.length();

        int ans = INT_MIN;

        for(int start = 0; start < n - k + 1; start++){
            for(int end = start + k - 1; end < n; end++){
                //cout<<start<<" "<<end<<" "<<endl;
                ans = max(ans, findDiff(s, start, end));
            }
        }
        


        return ans;
    }
};

************************************************************
              Better Approach: O(n^2)
************************************************************

class Solution {
public:
    
    int maxDifference(string s, int k) {
        
        int n = s.length();

        int ans = INT_MIN;

        vector<vector<int>> fre(n+1, vector<int>(5, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < 5; j++){
                fre[i+1][j] += fre[i][j] + (j == s[i] - '0');
            }
        }

        for(int start = 0; start < n - k + 1; start++){
            for(int end = start + k - 1; end < n; end++){
                //cout<<start<<" "<<end<<" "<<endl;
                
                int oddFre = INT_MIN, evenFre = INT_MAX;

                for(int i = 0; i < 5; i++){
                    if(fre[end+1][i] - fre[start][i] > 0){
                        
                        int freDiff = fre[end+1][i] - fre[start][i];
                        if(freDiff % 2) oddFre = max(oddFre, freDiff);

                        else
                            evenFre = min(evenFre, freDiff);
                    }
                }

                if(oddFre != INT_MIN && evenFre != INT_MAX)
                    ans = max(ans, oddFre - evenFre);
            }
        }
        


        return ans;
    }
};

