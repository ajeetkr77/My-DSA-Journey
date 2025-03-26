// ************  USING DIJKSTRAS ALGORITHM ****************

class Solution {
public:
    typedef pair<long long, int> P;
    const int M = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        
        unordered_map<int, vector<P>> adj;
        for(auto& road: roads){
            int u = road[0];
            int v = road[1];
            int w = road[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
       
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<long long> result(n, LLONG_MAX);
        vector<long long> pathCount(n, 0);

        result[0] = 0;
        pq.push({0, 0});
        pathCount[0] = 1;

        while(!pq.empty()){
            P p = pq.top();
            pq.pop();

            long long currNode = p.second;
            long long currTime = p.first;

            for(auto ngbr: adj[currNode]){
                if(currTime + ngbr.second < result[ngbr.first]){
                    result[ngbr.first] = currTime + ngbr.second;
                    pq.push({result[ngbr.first], ngbr.first});
                    pathCount[ngbr.first] = pathCount[currNode];
                }else if(currTime + ngbr.second == result[ngbr.first]){
                    pathCount[ngbr.first] = (pathCount[ngbr.first] + pathCount[currNode]) % M;
                }
            }
        }

        return pathCount[n-1];
    }
};
