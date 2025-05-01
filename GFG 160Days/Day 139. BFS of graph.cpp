class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int n = adj.size();
        
        vector<int> vis(n, 0);
        
        vector<int> ans;
        
        queue<int> q;
        
        vis[0] = 1;
        
        q.push(0);
        
        while(!q.empty()){
            
            int u = q.front();
            
            ans.push_back(u);
            
            q.pop();
            
            for(int it : adj[u]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        
        return ans;
    }
};
