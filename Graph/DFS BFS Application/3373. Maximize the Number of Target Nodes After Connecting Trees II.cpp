class Solution {
public:
    void bfs(unordered_map<int, vector<int>> &tree, vector<int> &mark, int &countZeroTree1, 
    int &countOneTree1, int n ){

        queue<pair<int, int>> q;
        mark.resize(n);
        vector<bool> vis(n);
        q.push({0, 0});
        vis[0] = 1;

        while(!q.empty()){
            int node = q.front().first;
            int value = q.front().second;
            mark[node] = value;

            if(value == 0) countZeroTree1++;
            if(value == 1) countOneTree1++;
            q.pop();

            for(auto & nbr : tree[node]){
                if(!vis[nbr]){
                    if(value == 0)
                        q.push({nbr, 1});
                    else
                        q.push({nbr, 0});
                    vis[nbr] = true;
                }
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
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

        vector<int> mark1;

        int countZeroTree1 = 0, countOneTree1 = 0;

        bfs(tree1, mark1, countZeroTree1, countOneTree1, n);

        for(int i = 0; i < n; i++){
            result1[i] = (mark1[i] == 0) ? countZeroTree1 : countOneTree1;
        }

        vector<int> result2(m);

        int countZeroTree2 = 0, countOneTree2 = 0;

        vector<int> mark2;

        bfs(tree2, mark2, countZeroTree2, countOneTree2, m);

        int maxValue = max(countZeroTree2, countOneTree2);

        for(int i = 0; i < n; i++){
            result1[i] += maxValue;
        }

        return result1;
    }
};
