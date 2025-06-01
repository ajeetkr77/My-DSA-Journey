******************************************************
  Time Complexity : O(n^2)
  Space Complexity : O(n)
******************************************************

class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        int n = mat1.size();
        
        set<int> s;
        
        int count = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                s.insert(mat2[i][j]);
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(s.find(x - mat1[i][j]) != s.end()){
                    count++;
                }
            }
        }
        
        return count;
    }
};

******************************************************
  Time Complexity : O(n^2)
  Space Complexity : O(1)
******************************************************

class Solution {
  public:
    bool find(vector<vector<int>> &mat2, int x, int n){
        
        int low = 1, high = n*n;
        
        while(low <= high){
            
            int mid = (low + high) / 2;
            
            int row = (mid - 1) / n;
            
            int col = (mid - 1) % n;
            
            if(mat2[row][col] == x) return true;
            
            else if(mat2[row][col]  < x){
                low = mid + 1;
            }
            
            else
                high = mid - 1;
        }
        
        return false;
    }
    
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        int n = mat1.size();
        
        
        int count = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(find(mat2, x - mat1[i][j], n))
                    count++;
            }
        }
        
        
        
        return count;
    }
};
******************************************************************
using constant space: 
******************************************************************
// C++ program to Count pairs from 
// two sorted matrices with given sum
#include <bits/stdc++.h>
using namespace std;

// Function to count pairs from two sorted matrices
// whose sum is equal to a given value x
int countPairs(vector<vector<int>>& mat1, 
               vector<vector<int>>& mat2, int x) {
    int n = mat1.size();
  
    // Indices for pointing current element in mat1 and mat2
    int i = 0, j = (n*n -1);

    int count = 0;

    // While there are elements in both matrices
    while (i < n*n && j >= 0) {
        int r1 = i/n, c1 = i%n;
        int r2 = j/n, c2 = j%n;
        int val = mat1[r1][c1] + mat2[r2][c2];

        if (val == x) {
            count++;

            // Move i and j
            i++;
            j--;
        } 
        else if (val < x) {
            i++;
        } 
        else {
            j--; 
        }
    }

    return count;
}

