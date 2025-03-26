*********************************    Brute Force Solution    ***********************
class Solution {
public:
   

    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {

        int n = recipes.size();
        int m = supplies.size();
        map<string, bool> mp;

        for(int i = 0; i < m; i++) mp[supplies[i]] = true;
        vector<bool> vis(n, false);

        int count = n;
        while(count--){
            bool isAny = false;
            for(int i = 0; i < n; i++){
                bool isCooked = true;
                if(!vis[i]){
                    for(auto &ingre : ingredients[i]){
                        if(!mp[ingre]) {
                            isCooked = false;
                            break;
                        }
                    }
                    if(isCooked == true){
                        vis[i] = true;
                        isAny = true;
                        mp[recipes[i]] = true;
                    }
                } 
            }
            if(!isAny) break;
        }
        

        vector<string> result;
        for(int i = 0; i < n; i++){
            if(vis[i]) result.push_back(recipes[i]);
        }
        return result;
    }
};

****************************************     Optimal Solution   ********************************************************
class Solution {
public:
   

    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> st(supplies.begin(), supplies.end());
        int n = recipes.size();
        unordered_map<string, vector<int> > adj;

        vector<int> indegree(n , 0);

        for(int i = 0; i < n; i++){
            for(string &ing: ingredients[i]){
                if(!st.count(ing)){
                    adj[ing].push_back(i);
                    indegree[i]++;
                }
            }
        }

        queue<int> q;
        for(int i  = 0; i < n; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        vector<string> result;

        while(!q.empty()){
            int i = q.front();
            q.pop();
            result.push_back(recipes[i]);

            for(auto & v : adj[recipes[i]]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        return result;
    }
};
