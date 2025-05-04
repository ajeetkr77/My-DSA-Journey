
class Solution {
  public:
    void dfs(vector<vector<int>> &ans, vector<pair<int, int>> dist, int sr, int sc, 
            int ocol, int ncol, int n, int m, vector<vector<int>>& image ){
            
        ans[sr][sc] = ncol;
        
        for(int i = 0; i < 4; i++){
            
            int nr = sr + dist[i].first;
            int nc = sc + dist[i].second;
            
            if((nr >= 0 && nr < n) && (nc >= 0 && nc < m) &&  image[nr][nc] == ocol &&
                ans[nr][nc] != ncol){
                dfs(ans, dist, nr, nc, ocol, ncol, n, m, image);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        
        
        int n = image.size();
        int m = image[0].size();
        
        vector<vector<int>> ans(n, vector<int>(m));
        
        //cout<<n<<" "<<m<<" "<<endl;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans[i][j] = image[i][j];
                //cout<<ans[i][j]<<" ";
            }
            //cout<<endl;
        }
        
        int oc = ans[sr][sc];
        
        vector<pair<int, int>> dist{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        
        dfs(ans, dist, sr, sc, oc, newColor, n, m, image);
        
        return ans;
    }
};


