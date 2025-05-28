***********************************************************
 Using BFS
Time Complexity : O(n^2 + m ^2)
***********************************************************


class Solution {
public:
    int bfs(unordered_map<int, vector<int>> &tree, int n, int d, int currNode){

        queue<pair<int, int>> q;
        vector<bool> vis(n);
        q.push({currNode, 0});

        vis[currNode] = 1;
        int count = 0;

        while(!q.empty()){
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            if(dist > d) continue;

            count++;

            for(auto & nbr : tree[node]){
                if(!vis[nbr]){
                    q.push({nbr, dist + 1});
                    vis[nbr] = true;
                }
            }
        }

        return count;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size();
        n++;
        int m = edges2.size();
        m++;

        unordered_map<int, vector<int>> tree1, tree2;

        for(int i = 0; i < n - 1; i++){
            int u = edges1[i][0];
            int v = edges1[i][1];
            tree1[u].push_back(v);
            tree1[v].push_back(u);
        }

        for(int i = 0; i < m - 1; i++){
            int u = edges2[i][0];
            int v = edges2[i][1];
            tree2[u].push_back(v);
            tree2[v].push_back(u);
        }

        vector<int> result1(n);

        for(int i = 0; i < n; i++){
            result1[i] = bfs(tree1, n, k, i);
        }
        

        vector<int> result2(m);

        for(int i = 0; i < m; i++){
            result2[i] = bfs(tree2, m, k - 1, i);
        }

        int maxValue = *max_element(result2.begin(), result2.end());

        for(int i = 0; i < n; i++){
            result1[i] += maxValue;
        }

        return result1;
    }
};

*************************************************************
Using DFS
*************************************************************

class Solution {
public:
    int dfs(unordered_map<int, vector<int>> &tree, int d, int currNode, int parentNode){
        if(d < 0) return 0;

        int count = 1;

        for(auto & nbr: tree[currNode]){
            if(nbr != parentNode){
                count += dfs(tree, d - 1, nbr, currNode);
            }
        }

        return count;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size();
        n++;
        int m = edges2.size();
        m++;

        unordered_map<int, vector<int>> tree1, tree2;

        for(int i = 0; i < n - 1; i++){
            int u = edges1[i][0];
            int v = edges1[i][1];
            tree1[u].push_back(v);
            tree1[v].push_back(u);
        }

        for(int i = 0; i < m - 1; i++){
            int u = edges2[i][0];
            int v = edges2[i][1];
            tree2[u].push_back(v);
            tree2[v].push_back(u);
        }

        vector<int> result1(n);

        for(int i = 0; i < n; i++){
            result1[i] = dfs(tree1, k, i, -1);
        }
        

        vector<int> result2(m);

        for(int i = 0; i < m; i++){
            result2[i] = dfs(tree2, k - 1, i, -1);
        }

        int maxValue = *max_element(result2.begin(), result2.end());

        for(int i = 0; i < n; i++){
            result1[i] += maxValue;
        }

        return result1;
    }
};
