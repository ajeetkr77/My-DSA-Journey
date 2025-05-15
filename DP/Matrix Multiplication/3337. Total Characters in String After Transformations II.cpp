class Solution {
public:
    int Mod = 1e9 + 7;
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        
        int n = s.length();
        vector<long long> fre(26, 0);


        //Initial Frequency
        for(char ch : s) fre[ch - 'a']++;

        

        //Matrix = degree * degree

        vector<vector<long long>> T(26, vector<long long>(26, 0));

        for(int i = 0; i < 26; i++){
            for(int add = 1; add <= nums[i]; add++){
                T[(i+add)% 26][i]++;
            }
        }

        //Matrix Exponentiation 

        vector<vector<long long>> result = matrixExpo(T, t);

        vector<long long> finalFre(26, 0);

        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                finalFre[j] = (finalFre[j] + (result[i][j] * fre[j]) % Mod) % Mod;
            }
        }

        long long ans = 0;

        for(int i = 0; i < 26; i++) ans = (ans + finalFre[i]) % Mod;

        return (int)ans;

    }

    vector<vector<long long>> matrixMultiply(vector<vector<long long>> A, vector<vector<long long>> B){
        vector<vector<long long>> ans(26, vector<long long>(26, 0));

        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                for(int k = 0; k < 26; k++){
                    ans[i][j] = (ans[i][j] + (A[i][k] * B[k][j]) % Mod) % Mod;
                }
            }
        }

        return ans;
    }

    vector<vector<long long>> matrixExpo(vector<vector<long long>> T, int t){

        if(t == 0){
            vector<vector<long long>> I(26, vector<long long>(26, 0));
            for(int i = 0; i < 26; i++) I[i][i] = 1;

            return I;
        }

        vector<vector<long long>> half = matrixExpo(T, t/2);

        vector<vector<long long>> full = matrixMultiply(half, half);

        if(t % 2 == 1){
            full = matrixMultiply(full, T);
        }

        return full;
    }
};
