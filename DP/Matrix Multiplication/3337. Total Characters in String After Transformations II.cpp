class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        const int MOD = 1e9 + 7;
        const int SIZE = 26;

        vector<vector<long long>> T(SIZE, vector<long long>(SIZE, 0));
        
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 1; j <= nums[i]; ++j) {
                T[i][(i + j) % SIZE]++;
            }
        }

        vector<vector<long long>> T_exp = matrixPower(T, t, MOD);

        vector<long long> freq(SIZE, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        long long total = 0;
        for (int j = 0; j < SIZE; ++j) {
            long long sum = 0;
            for (int i = 0; i < SIZE; ++i) {
                sum = (sum + freq[i] * T_exp[i][j]) % MOD;
            }
            total = (total + sum) % MOD;
        }

        return total;
    }

private:
    // Multipliy
    vector<vector<long long>> matrixMultiply(vector<vector<long long>>& A, vector<vector<long long>>& B, int MOD) {
        int SIZE = 26;
        vector<vector<long long>> result(SIZE, vector<long long>(SIZE, 0));
        for (int i = 0; i < SIZE; ++i) {
            for (int k = 0; k < SIZE; ++k) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < SIZE; ++j) {
                    result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return result;
    }

    //exponentiation
    vector<vector<long long>> matrixPower(vector<vector<long long>>& mat, int power, int MOD) {
        int SIZE = 26;
        vector<vector<long long>> result(SIZE, vector<long long>(SIZE, 0));
        for (int i = 0; i < SIZE; ++i) {
            result[i][i] = 1; 
        }

        vector<vector<long long>> base = mat;
        while (power > 0) {
            if (power % 2 == 1)
                result = matrixMultiply(result, base, MOD);
            base = matrixMultiply(base, base, MOD);
            power /= 2;
        }
        return result;
    }
};
