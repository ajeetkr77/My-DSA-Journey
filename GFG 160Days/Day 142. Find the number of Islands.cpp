class Solution {
  public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>> &vis, int row, 
    int col, vector<pair<int, int>>dir, int n, int m){
        
        vis[row][col] = 1;
        for(int i = 0; i < 8; i++){
            int nRow = row + dir[i].first;
            int nCol = col + dir[i].second;
            
            if((nRow >= 0 && nRow < n) && (nCol >= 0 && nCol < m) && 
            grid[nRow][nCol] == 'L' && vis[nRow][nCol] == 0){
                
                dfs(grid, vis, nRow, nCol, dir, n, m);
                
            }
        }
        
        
    }
    
    
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>>vis(row, vector<int>(col, 0));
        vector<pair<int, int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1,-1}, {-1,1},{1,-1},{1,1}};
        
        int islands = 0;
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 'L' && vis[i][j] == 0){
                    islands++;
                    dfs(grid, vis, i, j, dir, row, col);
                }
            }
        }
        
        return islands;
    }
};

