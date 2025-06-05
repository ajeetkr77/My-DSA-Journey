*******************************************
             Using dfs
*******************************************
class Solution {
  public:
    void dfs(unordered_map<int, vector<int>> &adj, vector<int> &vis, int &count,
                int src, int dest){
        
        if(src == dest){
            count++;
            return;
        }
        
        vis[src] = true;
        
        
        for(auto nbr : adj[src]){
            if(!vis[nbr]){
                dfs(adj, vis, count, nbr, dest);
            }
        }
        
        vis[src] = false;
    }
    
    
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        // Code here
        unordered_map<int, vector<int>> adj;
        
        int edge = edges.size();
        
        int degree = 0;
        
        for(int i = 0; i < edge; i++){
            
            int u = edges[i][0];
            
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        
        vector<int> vis(V, 0);
        
        int count = 0;
        
        dfs(adj, vis, count, src, dest);
        
        return count;
    }
};

******************************************
        Using Topological Sort
******************************************
class Solution {
  public:
    
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        // Code here
        unordered_map<int, vector<int>> adj;
        
        int edge = edges.size();
        
        vector<int> indegree(V, 0);
    
        
        for(int i = 0; i < edge; i++){
            
            int u = edges[i][0];
            
            int v = edges[i][1];
            
            adj[u].push_back(v);
            
            indegree[v]++;
        }
        
        queue<int> q;
        
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        vector<int> topoOrder;
        
        while(!q.empty()){
            
            int currNode = q.front();
            q.pop();
            topoOrder.push_back(currNode);
            
            for(auto nbr : adj[currNode]){
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        
        
        vector<int> ways(V, 0);
        
        ways[src] = 1;
        
        for(auto node : topoOrder){
            for(auto nbrNode : adj[node]){
                ways[nbrNode] += ways[node];
            }
            
        }
        
        return ways[dest];
    }
};
  
