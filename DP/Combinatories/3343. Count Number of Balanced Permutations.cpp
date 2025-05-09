
class Solution {
public:
    int n;
    int M = 1e9 + 7;
    int totalDigitSum = 0;
    long long totalPermPossible = 0;

    long long findPower(long long a, long long b){
        if(b == 0) return 1;

        long long half = findPower(a, b / 2);
        long long result = (half * half) % M;

        if(b % 2) result = (result * a) % M;

        return result;
    }

    int solve(int digit, int evenIndexDigitsCount, int currSum, vector<int> & fre, 
            vector<long long> & fermatFact, vector<vector<vector<int>>> &t){
            
        if(digit == 10){
            if(currSum == totalDigitSum / 2 && evenIndexDigitsCount == (n+1) / 2)
                return totalPermPossible;
            return 0;
        }

        if(t[digit][evenIndexDigitsCount][currSum] != -1)
            return t[digit][evenIndexDigitsCount][currSum];

        long long ways = 0;


       for(int count = 0; count <= min(fre[digit], (n+1)/2 - evenIndexDigitsCount); count++) {
            int evenPosCount = count;
            int oddPosCount  = fre[digit] - count;

            long long div = (fermatFact[evenPosCount] * fermatFact[oddPosCount])% M;

            long long val = solve(digit+1, evenIndexDigitsCount + evenPosCount, currSum + digit*count, fre, fermatFact, t);

            ways = (ways + (val * div) % M) % M;
        }

        return t[digit][evenIndexDigitsCount][currSum] = ways;
    }

    int countBalancedPermutations(string num) {
        n  = num.length();
        
        vector<int> fre(10, 0);

        for(int i = 0; i < n; i++){
            fre[num[i] - '0'] ++;
            totalDigitSum += num[i] - '0';
        }

        if(totalDigitSum % 2 == 1) return 0;

        //Precomputing Factorial

        vector<long long> fact(n+1, 1);
        fact[0] = 1;
        fact[1] = 1; 

        for(int i = 2; i <= n; i++){
            fact[i] = (fact[i-1] * i) % M;
        }

        //Precomputing FermatFactorial (inverse Factorial ---- (1 / x) % M)

        vector<long long> fermatFact(n+1, 1);

        for(int i = 0; i <= n; i++){
            fermatFact[i] = findPower(fact[i], M - 2) % M;
        }

        totalPermPossible = (1LL * fact[(n+1) / 2] * fact[n / 2]) % M;

        int digit = 0;

        int evenIndexDigitsCount = 0;

        int currSum = 0;

        vector<vector<vector<int>>> t(10, vector<vector<int>>((n + 1) / 2 + 1, vector<int>(totalDigitSum + 1, -1)));


        return solve(digit, evenIndexDigitsCount, currSum, fre, fermatFact, t);
    }
};
