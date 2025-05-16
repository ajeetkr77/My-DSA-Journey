*******************************************************
  Time Complexity: O(k * n)
*******************************************************


class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& nums) {
        // code here
        int k = nums.size();

        vector<int> vec(k, 0); //{0, 0, 0....}

        vector<int> resultRange = {-1000000, 1000000}; //(a, b)

        while(true) {
            int minEl        = INT_MAX;
            int maxEl        = INT_MIN;
            int minElListIdx = 0;

            for(int i = 0; i < k; i++) {
                int listIdx = i;
                int elIdx = vec[i];
                int element = nums[listIdx][elIdx];

                if(element < minEl) {
                    minEl = element;
                    minElListIdx = listIdx;
                }

                maxEl = max(maxEl, element);
            }

            //raneg (minEl, maxEl)
            if(maxEl - minEl < resultRange[1] - resultRange[0]) {
                resultRange[0] = minEl;
                resultRange[1] = maxEl;
            }

            //now shorten this range by moving minElement idx
            int nextIndex = vec[minElListIdx]+1;
            if(nextIndex >= nums[minElListIdx].size()) {
                break;
            }
            vec[minElListIdx] = nextIndex;
        }

        return resultRange;
    }
};



************************************************************
 T C = O(n * log(k))
************************************************************

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        int k = nums.size();
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        int maxEle = INT_MIN;

        vector<int> result = {-1000000, 1000000};

        for(int i = 0; i < k; i++){
            pq.push({nums[i][0], i, 0});
            maxEle = max(maxEle, nums[i][0]);
        }

        while(!pq.empty()){

            vector<int> minValue = pq.top();
            pq.pop();

            int minEle = minValue[0];
            int minEleList = minValue[1];
            int minEleIndex = minValue[2];

            if(maxEle - minEle < result[1] - result[0]){
                result[0] = minEle;
                result[1] = maxEle;
            }

            int nextIndex = minEleIndex + 1;

            if(nextIndex >= nums[minEleList].size()){
                break;
            }

            pq.push({nums[minEleList][nextIndex], minEleList, nextIndex});
            maxEle = max(maxEle, nums[minEleList][nextIndex]);
        }

        return result;
    }
};
