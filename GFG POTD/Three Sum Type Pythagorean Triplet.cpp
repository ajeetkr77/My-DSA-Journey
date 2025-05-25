class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        
        int maxEl = INT_MIN; 
        
        int n = arr.size();
        
        for(int i = 0; i < n; i++) maxEl = max(maxEl, arr[i]);
        
        vector<bool> vis(maxEl+1, false);
        
        for(int i = 0; i < n; i++) vis[arr[i]] = true;
        
        for(int i = 1; i <= maxEl; i++){
            
            if(!vis[i]) continue;
            
            int a = i;
            
            for(int j = 1; j <= maxEl; j++){
                
                if(j == i || !vis[j]) continue;
                
                int b = j;
                
                int c = a*a + b*b;
                
                int sqc = sqrt(c);
                
                if(sqc * sqc != a * a + b * b || sqc > maxEl) continue;
                
                if(vis[sqc]) return true;
            }
        }
        
        return false;
    }
};
