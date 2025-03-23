************************** Function to find the shortest distance of all the vertices from the source vertex src in connected graph ***********************************
***********************  USING PRIORITY QUEUE DATA STRUCTURE  ******************************

class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        int n = adj.size();
        vector<int> result(n, INT_MAX);
        result[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0, src});
        
        while(!pq.empty()){
            pair<int, int> p = pq.top();
            pq.pop();
            int currNode = p.second;
            int currCost = p.first;
            for(auto nbrNode: adj[currNode]){
                if(currCost + nbrNode.second < result[nbrNode.first]){
                    result[nbrNode.first] = currCost + nbrNode.second;
                    pq.push({result[nbrNode.first], nbrNode.first});
                }
            }
        }
        return result;
        
    }
};

****************************  USING SET DATA STRUCTURE  ***********************************

class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        int n = adj.size();
        vector<int> result(n, INT_MAX);
        result[src] = 0;
        
        set<pair<int,int>> st;
        st.insert({0, src});
        
        while(!st.empty()){
            
            auto &it = *st.begin();
            int currNode = it.second;
            int currCost = it.first;
            st.erase(it);
            
            for(auto nbrNode: adj[currNode]){
                if(currCost + nbrNode.second < result[nbrNode.first]){
                    if(st.find({result[nbrNode.first], nbrNode.first}) != st.end())
                        st.erase({result[nbrNode.first], nbrNode.first});
                    result[nbrNode.first] = currCost + nbrNode.second;
                    st.insert({result[nbrNode.first], nbrNode.first});
                }
            }
        }
        return result;
        
    }
};
