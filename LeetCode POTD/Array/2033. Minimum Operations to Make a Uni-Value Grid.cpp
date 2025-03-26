

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> flat;
        int rem = grid[0][0] % x;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                flat.push_back(grid[i][j]);
                if(grid[i][j] % x != rem) return -1;
            }
        }

        sort(flat.begin(), flat.end());
        int mid = m*n / 2;
        int minStep = 0;

        for(int i = 0; i < m*n; i++){
            minStep += abs(flat[i] - flat[mid]) / x;
        }

        return minStep;
    }
};
