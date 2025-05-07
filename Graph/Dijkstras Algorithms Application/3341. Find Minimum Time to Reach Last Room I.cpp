class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<int>> result(n, vector<int>(m, INT_MAX));
        

        // for(int j = 1; j < m; j++){
        //     if(dp[0][j-1] >= moveTime[0][j]) dp[0][j] = dp[0][j-1] + 1;
        //     else
        //         dp[0][j] = moveTime[0][j] + 1;
        // }

        // for(int i = 1; i < n; i++){
        //     if(dp[i-1][0] >= moveTime[i][0]) dp[i][0] = dp[i-1][0] + 1;
        //     else
        //         dp[i][0] = moveTime[i][0] + 1;
        // }

        // for(int i = 1; i < n; i++){
        //     for(int j = 1; j < m; j++){
        //         int mini = min(dp[i-1][j], dp[i][j-1]);

        //         if(mini >= moveTime[i][j]) dp[i][j] = mini + 1;
        //         else
        //             dp[i][j] = moveTime[i][j] + 1;
        //     }
        // }

        // return dp[n-1][m-1];

        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0, {0, 0}});

        vector<pair<int, int>> dir{{-1, 0}, {1,0}, {0,1},{0,-1}};

        while(!pq.empty()){

            pair<int, pair<int, int>> p = pq.top();
            pq.pop();

            int currTime = p.first;
            int r = p.second.first;
            int c = p.second.second;

             if(r == n-1 && c == m-1) {
                return currTime;
            }
            
            for(int i = 0; i < 4; i++){
                int nR = r + dir[i].first;
                int nC = c + dir[i].second;

                if((nR >= 0 && nR < n) && (nC >= 0 && nC < m)){
                     int wait    = max(moveTime[nR][nC] - currTime, 0);
                     int arrTime = currTime + wait + 1;

                    if(result[nR][nC] > arrTime){
                        result[nR][nC] = arrTime;
                        pq.push({arrTime, {nR, nC}});
                    }
                }
            }

        }

        return -1;
    }
};
