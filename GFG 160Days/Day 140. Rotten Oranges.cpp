class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        int n = mat.size();
        
        int m = mat[0].size();
        
        //vector<vector<int>> vis(n, vector<int>(m, 0));
        
        vector<pair<int, int>> dir{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        
        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 2){
                    q.push({i, j});
                   // vis[i][j] = 1;
                }
            }
        }
        
        int minTime = 0;
        
        while(!q.empty()){
            
            int flag = 0;
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                pair<int, int> p = q.front();
                q.pop();
                
                int row = p.first;
                int col = p.second;
                
                for(int j = 0; j < 4; j++){
                    int nRow = row + dir[j].first;
                    int nCol = col + dir[j].second;
                    
                    if((nRow >= 0 && nRow < n) && (nCol >= 0 && nCol < m) && mat[nRow][nCol] == 1 
                        ){
                        mat[nRow][nCol] = 2;
                        q.push({nRow, nCol});
                        flag = 1;
                    }
                }
            }
            
            if( flag ) minTime++;
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1){
                    return -1;
                }
            }
        }
        
        return minTime;
    }
};
