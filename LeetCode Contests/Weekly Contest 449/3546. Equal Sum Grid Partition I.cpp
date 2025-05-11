*************************************************************************************
    Solution During Test
*************************************************************************************

  class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<long long> rowSum(n, 0), colSum(m, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                rowSum[i] += grid[i][j];
            }
        }

        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                colSum[j] += grid[i][j];
            }
        }

        vector<long long> rowPre(n, 0), colPre(m, 0);

        for(int i = 0; i < n; i++) rowPre[i] = rowSum[i];

        for(int i = 1; i < n; i++) rowPre[i] += rowPre[i-1];

        for(int j = 0; j < m; j++) colPre[j] = colSum[j];

        for(int j = 1; j < m; j++) colPre[j] += colPre[j-1];
        
        
        for(int i = n-2; i >= 0; i--) rowSum[i] += rowSum[i+1];

        for(int j = m-2; j >=0; j--) colSum[j] += colSum[j+1];

        // for(int i = 0; i<n; i++) cout<<rowSum[i]<<" ";
        // cout<<endl;
        // for(int j = 0; j < m; j++) cout<<colSum[j]<<" ";

        for(int i = 0; i < n - 1; i++){
            if(rowPre[i] == rowSum[i+1]) return true;
        }

        for(int j = 0; j < m - 1; j++){
            if(colPre[j] == colSum[j+1]) return true;
        }
        
        return false;
    }
};



*********************************************************************************
      Updated and cleaned Solution
*********************************************************************************

  class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<long long> rowSum(n, 0), colSum(m, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                rowSum[i] += grid[i][j];
            }
            if(i > 0) rowSum[i] += rowSum[i-1];
        }

        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                colSum[j] += grid[i][j];
            }
            if(j > 0) colSum[j] += colSum[j-1];
        }
        
        
        for(int i = 0; i < n - 1; i++){
            if(rowSum[i] == rowSum[n-1] - rowSum[i]) return true;
        }

        for(int j = 0; j < m - 1; j++){
            if(colSum[j] == colSum[m-1] - colSum[j]) return true;
        }
        
        return false;
    }
};

************************************************************************************
        Using Constant Space 
************************************************************************************
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        
        long long totalSum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) totalSum += grid[i][j];
        }


        long long partialSum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                partialSum += grid[i][j];
            }
            if(partialSum == totalSum - partialSum) return true;
        }

        partialSum = 0;

        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                partialSum += grid[i][j];
            }
            if(partialSum == totalSum - partialSum) return true;
        }
        
        return false;
    }
};
    
