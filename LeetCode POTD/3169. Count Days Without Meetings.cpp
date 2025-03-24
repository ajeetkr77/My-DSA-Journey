
*********************** NAIVE APPROACH ***************************
  TIME COMPLEXITY : O(NLOGN)
  SPACE COMPLEXITY: O(N)
******************************************************************

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());

        vector<vector<int>> mergeMeetings;
        mergeMeetings.push_back(meetings[0]);

        for(int i = 1; i < n; i++){
            int sz = mergeMeetings.size();
            if(meetings[i][0] <= mergeMeetings[sz-1][1]){
                int l = mergeMeetings[sz-1][0];
                int r = max(meetings[i][1], mergeMeetings[sz-1][1]);
                mergeMeetings.pop_back();
                mergeMeetings.push_back({l, r});
            }else{
                mergeMeetings.push_back(meetings[i]);
            }
        }

        int count = 0;
        count += mergeMeetings[0][0] - 1;
        int size = mergeMeetings.size();

        // for(int i = 0; i < size; i++){
        //     cout<<mergeMeetings[i][0]<<" "<<mergeMeetings[i][1]<<endl;
        // }

        for(int i = 1; i < size; i++){
            count += (mergeMeetings[i][0] - mergeMeetings[i-1][1] - 1);
        }

        count += days - mergeMeetings[size-1][1];
        return count;
    }
};

****************************** OPTIMAL SOLUTION *****************************
  TIME COMPLEXITY : O(NLOGN)
  SPACE COMPLEXITY: O(1)
  Source : Codestorywithmik
*****************************************************************************

  class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());


        int count = 0;
        count += meetings[0][0] - 1;
        int end = meetings[0][1];
        int start;

        for(int i = 1; i < n; i++){
            start = meetings[i][0];
            if(start > end)
                count += (start - end  - 1);
            end = max(end, meetings[i][1]);
        }

        count += days - end;
        return count;
    }
};

  
