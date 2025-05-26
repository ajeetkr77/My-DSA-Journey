class Solution {
public:
    
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        int n = colors.length();
        int m = edges.size();
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);

        for(int i = 0; i < m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        vector<vector<int>> dp(n, vector<int>(26, 0));

        for(int u = 0; u < n; u++){
            if(indegree[u] == 0){
                q.push(u);
                dp[u][colors[u] - 'a'] = 1;
            }
        }

        
        int count = 0, maxColorValue = INT_MIN;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            count++;

            maxColorValue = max(maxColorValue, dp[u][colors[u] - 'a']);

            for(auto v: adj[u]){

                for(int i = 0; i < 26; i++){
                    dp[v][i] = max(dp[v][i], dp[u][i] + (colors[v] - 'a' == i));
                }

                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }
        

        return (count == n) ? maxColorValue : -1;
    }
};
