
******************** Brute Force Approach ********************

  T.C = O(N^3)

****************************************************************

  class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int maxPoints = INT_MIN;

        //for(int i = 0; i < n; i++) cout<<points[i][0]<<" "<<points[i][1];

        if(n == 1) return 1;

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int point = 2; 
                float slope1 = points[i][1] - points[j][1];
                if(points[i][0] - points[j][0] != 0){
                    slope1 /= points[i][0] - points[j][0];
                    for(int k = j+1; k < n; k++){
                        float slope2 = points[i][1] - points[k][1];
                        if(points[i][0] - points[k][0] != 0){
                            slope2 /= points[i][0] - points[k][0];
                            if(slope1 == slope2) point++;
                            //cout<<slope1<<" "<<slope2;
                        }
                    }
                } 

                if(points[i][0] - points[j][0] == 0){
                    for(int k = j+1; k < n; k++){
                        if(points[i][0] == points[k][0]) point++;
                    }
                }

                maxPoints = max(maxPoints, point);
            }
        }

        return maxPoints;
    }
};

**************************** Optimized Approach ***************

  T.C = O(N^2)

***************************************************************

  class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        int maxPoints = INT_MIN;

        if(n == 1) return 1;

        for(int i = 0; i < n; i++){

            unordered_map<double, int> mp;

            for(int j = 0; j < n; j++){
                
                if(i == j) continue;

                auto dy = points[j][1] - points[i][1];

                auto dx = points[j][0] - points[i][0];

                auto theta = atan2(dy, dx);

                mp[theta]++;
            }

            for(auto &it : mp){

                maxPoints = max(maxPoints, it.second + 1);

            }

        }

        return maxPoints;
    }
};
