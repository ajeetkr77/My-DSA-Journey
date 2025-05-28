class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        // code here
        unordered_map<int, vector<int>> rows, cols;
        
        int n = mat.size(), m = mat[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j]){
                    rows[i].push_back(j);
                    cols[j].push_back(i); 
                }
            }
        }
        
        for(auto it: rows){
            int row = it.first;
            vector<int> colOne = it.second;
            
            int Sz = colOne.size();
            
            for(int i = 0;  i < Sz; i++){
                int col1 = colOne[i];
                for(int j = i + 1; j < Sz; j++){
                    int col2 = colOne[j];
                    
                    if(cols[col1].size() >= 2){
                        
                        int siz = cols[col1].size();
                        
                        for(int k = 0; k < siz; k++){
                           if(cols[col1][k] == row) continue;
                           
                           int row2 = cols[col1][k];
                           
                           if(mat[row2][col2]) return true;
                        }
                    }
                }
            }
        }
        
        return false;
        
    }
};
***************************************************************
  Naive Approach : O(n^2 * m^2)
***************************************************************

// C++ program to check if there exists a submatrix
// with all 1s at the corners using Naive Approach
#include <bits/stdc++.h>
using namespace std;

// Function to check for a rectangle with corners as 1
bool ValidCorner(vector<vector<int>> &mat) {
    
    int rows = mat.size();
    int cols = mat[0].size();

    // Iterate over all pairs of rows
    for (int top = 0; top < rows - 1; top++) {
        for (int bottom = top + 1; bottom < rows; bottom++) {

            // Iterate over all pairs of columns
            for (int left = 0; left < cols - 1; left++) {
                for (int right = left + 1; right < cols; right++) {

                    // Check all four corners of the submatrix
                    if (mat[top][left] == 1 && mat[top][right] == 1 &&
                        mat[bottom][left] == 1 && mat[bottom][right] == 1) {
                        return true;
                    }
                }
            }
        }
    }

    // No such rectangle found
    return false;
}

// Driver code
int main() {

    vector<vector<int>> mat = {
        {1, 0, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0},
        {1, 0, 1, 0, 1}
    };
    
    if (ValidCorner(mat)) {
        cout << "true";
    } 
    else {
        cout << "false";
    }

    return 0;
}

****************************************************************
Optimal Approach
****************************************************************

// C++ program to check if there exists a submatrix
// with all 1s at the corners using Simple Hashing
#include <bits/stdc++.h>
using namespace std;

// Function to check for a rectangle with corners as 1
bool ValidCorner(vector<vector<int>> &mat) {
    
    int rows = mat.size();
    int cols = mat[0].size();

    // Hash set to store pairs of columns having 1 in a row
    unordered_set<string> seen;

    // Iterate through each row
    for (int i = 0; i < rows; i++) {

        // Check all column pairs where cell is 1
        for (int col1 = 0; col1 < cols - 1; col1++) {
            if (mat[i][col1] == 0) continue;

            for (int col2 = col1 + 1; col2 < cols; col2++) {
                if (mat[i][col2] == 0) continue;

                // Form a unique key from column pair
                string key = to_string(col1) + "," + to_string(col2);

                // If this pair seen before → rectangle exists
                if (seen.find(key) != seen.end()) {
                    return true;
                }

                // Otherwise store it
                seen.insert(key);
            }
        }
    }

    // No rectangle found
    return false;
}

// Driver code
int main() {

    vector<vector<int>> mat = {
        {1, 0, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0},
        {1, 0, 1, 0, 1}
    };

    if (ValidCorner(mat)) {
        cout << "true";
    } 
    else {
        cout << "false";
    }

    return 0;
}
