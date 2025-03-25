class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> x_dirs;
        vector<pair<int, int>> y_dirs;

        int size = rectangles.size();

        for(int i = 0; i < size; i++){
            x_dirs.push_back({rectangles[i][0], rectangles[i][2]});
            y_dirs.push_back({rectangles[i][1], rectangles[i][3]});
        }

        sort(x_dirs.begin(), x_dirs.end());
        sort(y_dirs.begin(), y_dirs.end());

        int index = 1; 

        // Try to use function in case of similar applicability of code 
        // it will enhance readability also

        for(int i = 1; i < size; i++){
            if(x_dirs[i].first >= x_dirs[index-1].second){
                index++;
                x_dirs[index-1] = x_dirs[i];
            }else{
                x_dirs[index-1] = {x_dirs[index-1].first, max(x_dirs[index-1].second, x_dirs[i].second)};
            }
        }

        if(index >= 3) return true;

        index = 1;

        for(int i = 1; i < size; i++){
            if(y_dirs[i].first >= y_dirs[index-1].second){
                index++;
                y_dirs[index-1] = y_dirs[i];
            }else{
               y_dirs[index-1] = {y_dirs[index-1].first, max(y_dirs[index-1].second, y_dirs[i].second)};
            }
        }
        
        if(index >= 3) return true;
        return false;
    }
};
