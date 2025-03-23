class Solution {
  public:
    typedef pair<int, int> P;
    
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<int> par(n+1);
        for(int i = 0; i <= n; i++) par[i] = i;
        vector<int> result(n+1, INT_MAX);
        
        unordered_map<int, vector<P>> adj;
        
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj[v].push_back({u, w});
            adj[u].push_back({v, w});
        }
        
        priority_queue<P, vector<P>, greater<P>> pq;
        result[1] = 0;
        pq.push({0, 1});
        
        while(!pq.empty()){
            P p = pq.top();
            pq.pop();
            
            int currV = p.second;
            int currW = p.first;
            
            for(auto & ngbr: adj[currV]){
                if(currW + ngbr.second < result[ngbr.first]){
                    result[ngbr.first] = currW + ngbr.second;
                    pq.push({result[ngbr.first], ngbr.first});
                    par[ngbr.first] = currV;
                }
            }
        }
        
        if(result[n] != INT_MAX){
             vector<int> path;
             int i = n;
             while(par[i] != i){
                path.push_back(i);
                i = par[i];
             }
             path.push_back(1);
             path.push_back(result[n]);
             reverse(path.begin(), path.end());
             return path;
        }
        return {-1};
    }
};
