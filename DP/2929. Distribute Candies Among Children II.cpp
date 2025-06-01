class Solution {
public:
    int t[1000001];
    long long solve(int i, int limit, int n){
        if(i == 3){
            return n == 0;
        }

        if(t[i] != -1) return t[i];

        long long cal = 0;

        for(int j = 0; j <= limit; j++){
            cal += solve(i+1, limit, n - j);
        }

        return cal;
    }
    long long distributeCandies(int n, int limit) {

        memset(t, -1, sizeof(t));
        
        long long ans = solve(0, limit, n);

        return ans;
    }
};


*******************************************

class Solution {
public:
   
    long long distributeCandies(int n, int limit) {

        int minCh1 = max(0, n - 2*limit);
        int maxCh1 = min(n, limit);

        // fixing child1

        long long ways = 0;

        for(int i = minCh1; i <= maxCh1; i++){

            int N = n - i;

            int minCh2 = max(0, N - limit);
            int maxCh2 = min(N, limit);

            ways += maxCh2 - minCh2 + 1;
        }

        return ways;
    }
};
