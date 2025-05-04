// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        int n = edges.size();
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for(int i = 0; i < n; i++){
            
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<int> result(V, INT_MAX);
        
        result[src] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>>pq; 
        
        pq.push({0, src});
        
        while(!pq.empty()){
            
            pair<int, int> p = pq.top();
            pq.pop();
            
            int dist = p.first;
            int node = p.second;
            
            for(auto& nbrNode: adj[node]){
                if(dist + nbrNode.second < result[nbrNode.first]){
                    result[nbrNode.first] = dist + nbrNode.second;
                    pq.push({result[nbrNode.first], nbrNode.first});
                }
            }
        }
        
        return result;
    }
};
