********************************************************
  T C = O(sqrt(N))
  ************************


class Solution {
  public:
    int largestPrimeFactor(int n) {
        // code here
        int ans;
        
        while( n % 2 == 0){
            ans = 2;
            n /= 2;
        }
        
        for(int i = 3; i * i <= n; i+=2){
            while(n % i == 0){
                ans = i;
                n /= i;
            }
        }
        if(n > 2){
            ans = n;
        }
        return ans;
    }
};

*************************************************************
T C = O(logn) 
S C = O(n)
*************************************************************
Prime Factorization using Sieve O(log n) for multiple queries

  Given a positive integer n, calculate and return all prime numbers less than or equal to n using the Sieve of Eratosthenes algorithm.
************************************************************************************************************
// User function Template for C++
class Solution {
  public:
    vector<int> sieveOfEratosthenes(int n) {
        // Write Your Code here
        vector<bool> visited(n+1, true);
        vector<int> ans;
        
        for(int p = 2; p*p <= n; p++){
            if(visited[p]){
                for(int j = p*p; j <=n; j+=p){
                    visited[j] = false;
                }
            }
        }
        
        for(int p = 2; p <= n; p++){
            if(visited[p])
                ans.push_back(p);
        }
        return ans;
    }
};

************************************************************************************************************
Given a number n, print least prime factors of all numbers from 1 to n
********************************************

class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        // code here
        vector<int> vis(n+1, 1);
        vis[0] = 0;
        vis[1] = 1;
        
        for(int p = 2; p <= n; p++){
            if(vis[p] == 1){
                vis[p] = p;
                for(int j = p*p; j <=n; j+=p){
                    if(vis[j] == 1)
                        vis[j] = p;
                }
            }
        }
        
        return vis;
    }
};



