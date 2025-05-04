class Solution {
public:
    int findCombination(int n){

        if( n == 2 ) return 1; 

        return (n * (n-1)) / 2;

    }

    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        
        int n = dominoes.size();

        map<pair<int, int>, int> mp;

        for(int i = 0; i < n; i++){
            mp[{min(dominoes[i][0], dominoes[i][1]), max(dominoes[i][0], dominoes[i][1])}]++;
        }

        int ans = 0;
        for(auto& u : mp){
            //cout<<u.second<<" ";
            if(u.second >= 2){
                ans += findCombination(u.second);
            }
        }

        return ans;
    }
};
