**************************** Intutive Solution ****************************
  Time Complexity : O(N)
  Space Complexity : O(N)
***************************************************************************

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> count(n, 1);

        //moving left to right
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1])
                count[i] = count[i-1] + 1;
        }

        //moving right to left
        for(int i = n-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1] && count[i] <= count[i+1])
                count[i] = count[i+1] + 1;
        }

        for(int i = 1; i < n; i++){
            count[i] += count[i-1];
        }

        return count[n-1];
    }
};

*********************************** Optimal Solution **************************
  Time Complexity : O(N)
  Space Complexity : O(1)
*******************************************************************************

  class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candy = n;
        int i = 1;

        while(i < n){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }

            //Moving upward to the mountain
            int peak = 0;
            while(i < n && ratings[i] > ratings[i-1]){
                peak++;
                candy += peak;
                i++;
            }

            int dip = 0;
            //Moving downward to the mountain

            while(i < n && ratings[i] < ratings[i-1]){
                dip ++;
                candy += dip;
                i++;
            }
            candy -= min(dip, peak);
        }
        return candy;
    }
};
