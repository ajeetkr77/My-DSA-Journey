**********************************   Using DFS   ****************************
class Solution {
public:
    int vertexN, edgeN;
    void dfs(int u, unordered_map<int, vector<int>>& adj, vector<int>& vis){
        vis[u] = 1;
        vertexN += 1;
        edgeN += adj[u].size();

        for(auto v : adj[u]){
            if(!vis[v])
                dfs(v, adj, vis);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        vector<int> vis(n, 0);

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int count = 0;

        for(int u = 0; u < n; u++){
            if(!vis[u]){
                vertexN = 0, edgeN = 0;
                dfs(u, adj, vis);
                if((vertexN* (vertexN-1)) / 2 == edgeN / 2) count++;
            }
        }

        return count;
    }
};
**********************************   Using BFS   ****************************

class Solution {
public:
    int vertexN, edgeN;
    void bfs(int u, unordered_map<int, vector<int>>& adj, vector<int>& vis){
        queue<int> q;
        q.push(u);
        vis[u] = 1;
        
        while(!q.empty()){
            int s = q.front();
            q.pop();
            vertexN ++;
            edgeN += adj[s].size();

            for(auto v: adj[s]){
                if(!vis[v]){
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        vector<int> vis(n, 0);

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int count = 0;

        for(int u = 0; u < n; u++){
            if(!vis[u]){
                vertexN = 0, edgeN = 0;
                bfs(u, adj, vis);
                if((vertexN* (vertexN-1))  == edgeN) count++;
            }
        }

        return count;
    }
};

**********************************   Using DSU   ****************************
class Solution {
public:
    class DSU {
    public:

        vector<int> parent;
        vector<int> size;

        DSU(int n){
            parent.resize(n);
            size.resize(n);

            for(int i = 0; i < n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }

        int Find(int x){
            if(x == parent[x])
                return x;
            return parent[x] = Find(parent[x]);
        }

        void UnionBySize(int x, int y){
            int x_par = Find(x);
            int y_par = Find(y);

            if(x_par == y_par)
                return;
            
            if(size[x_par] > size[y_par]){
                parent[y_par] = x_par;
                size[x_par] += size[y_par];
            }else if(size[x_par] < size[y_par]){
                parent[x_par] = y_par;
                size[y_par] += size[x_par];
            }else{
                parent[y_par] = x_par;
                size[x_par] += size[y_par];
            }

        }
    };

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        DSU dsu(n);
        unordered_map<int, int> mp; // root-> edges

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            dsu.UnionBySize(u,v);
        }

        // count the edges for each root
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int root = dsu.Find(u);
            mp[root]++;
        }

        int count = 0;

        for(int u = 0; u < n; u++){
            if(dsu.Find(u) == u){
                int v = dsu.size[u];
                int e = mp[u];
                if((v* (v-1)) / 2  == e) count++;
            }
        }

        return count;
    }
};
