
class Solution {
  public:
    void dfsSearch(vector<vector<int>>& adj, vector<int> &ans, vector<int> &vis,  int u){
        vis[u] = 1;
        
        ans.push_back(u);
        
        for(auto it : adj[u]){
            if(!vis[it]){
                dfsSearch(adj, ans, vis, it);
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        
        vector<int> vis(n, 0);
        
        vector<int> ans;
        
        dfsSearch(adj, ans, vis, 0);
        
        return ans;
    }
};
