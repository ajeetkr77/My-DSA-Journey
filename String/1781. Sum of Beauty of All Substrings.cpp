*************************************************
Brute Force Approach
*************************************************

class Solution {
public:
    int calculateBeauty(string &s){
        vector<int> fre(26, 0);

        int n = s.length();
        int maxFre = 0, minFre = INT_MAX;

        for(int i = 0; i < n; i++){
            fre[s[i] - 'a']++;
        } 

        for(int i = 0; i < 26; i++){
            if(fre[i] > 0){
                maxFre = max(maxFre, fre[i]);
                minFre = min(minFre, fre[i]);
            }
        }

        return maxFre - minFre;
    }

    int beautySum(string s) {
        
        int n = s.length();
        int ans = 0;
        
        for(int len = 3; len <= n; len++){
            for(int i = 0; i < n - len + 1; i++){
                string temp = s.substr(i, len);
                //cout<<temp<<" ";
                ans += calculateBeauty(temp);
            }
        }

        return ans;
    }
};

****************************************************
Optimal Approach 
****************************************************

  class Solution {
public:
    
    int beautySum(string s) {
        
        int n = s.length();
        int ans = 0;

        vector<vector<int>> fre(n+1, vector<int>(26, 0));

        for(int i = 0; i < n; i++){
            fre[i+1][s[i]-'a'] = 1;
            for(int j = 0; j < 26; j++){
                fre[i+1][j] += fre[i][j];
            }
        }
        
        for(int len = 3; len <= n; len++){
            for(int i = 0; i < n - len + 1; i++){
                
                int j = i + len;

                int minFre = INT_MAX, maxFre = 0;

                for(int k = 0; k < 26; k++){
                    if(fre[j][k] - fre[i][k] > 0){
                        minFre = min(minFre, fre[j][k] - fre[i][k]);
                        maxFre = max(maxFre, fre[j][k] - fre[i][k]);
                    }
                }
                
                ans += (maxFre - minFre);
            }
        }

        return ans;
    }
};
