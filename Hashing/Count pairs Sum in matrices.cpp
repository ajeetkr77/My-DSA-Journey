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
