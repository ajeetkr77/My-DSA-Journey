class Solution {
public:
    void bfs(unordered_map<int, int> &adj, vector<int> &result, int node, int n){

        queue<pair<int, int>> q;
        q.push({node, 0});
        vector<int> vis(n, 0);
        vis[node] = 1;
        

        while(!q.empty()){
            
            int currNode = q.front().first;
            int currDist = q.front().second;
            result[currNode] = currDist;
            q.pop();

            if(adj.count(currNode)){
                int nbr = adj[currNode];
                if(!vis[nbr]){
                    q.push({nbr, currDist + 1});
                    vis[nbr] = 1;
                } 
            }


        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        unordered_map<int, int> adj;

        for(int i = 0; i < n; i++){
            if(edges[i] != -1){
                adj[i] = edges[i];
            }
        }

        vector<int> result1(n, -1);

        bfs(adj, result1, node1, n);

        vector<int> result2(n, -1);

        bfs(adj, result2, node2, n);

        int smallestIndex = -1;

        int miniDistance = INT_MAX;

        for(int i = 0; i < n; i++){
            if(result1[i] != -1 && result2[i] != -1){
                if(max(result1[i], result2[i]) < miniDistance){
                    miniDistance = max(result1[i], result2[i]);
                    smallestIndex = i;
                }
            }
        }

        return smallestIndex;
    }
};
