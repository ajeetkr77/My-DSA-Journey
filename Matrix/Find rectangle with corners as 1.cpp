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
