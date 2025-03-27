*********************** Better Solution ************************************
  With Extra space 
  *************************************************

class Solution {
public:
    int findDominant(vector<int>& nums){
        int n = nums.size();
        int count = 1, ele = nums[0];

        for(int i = 1; i < n; i++){
            if(nums[i] == ele) count++;
            else{
                count--;
                if(count == 0){
                    ele = nums[i];
                    count = 1;
                }
            }
        }
        return ele;
    }
    int minimumIndex(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        int dominant = findDominant(nums);
        vector<int> freq(n, 0);

        if(nums[0] == dominant) freq[0] = 1;

        for(int i = 1; i < n; i++){
            if(nums[i] == dominant) freq[i] = freq[i-1] + 1;
            else
                freq[i] = freq[i-1];
        }

        for(int i = 0; i < n; i++){
            if(freq[i] * 2 > i+1 && (freq[n-1] - freq[i])*2 > n-i-1 )
                return i;
        }
        return ans;
    }
};

***************************  Optimal Solution *******************************

  Without using extra space.

***************************************************************************

  class Solution {
public:
    int findDominant(vector<int>& nums){
        int n = nums.size();
        int count = 1, ele = nums[0];

        for(int i = 1; i < n; i++){
            if(nums[i] == ele) count++;
            else{
                count--;
                if(count == 0){
                    ele = nums[i];
                    count = 1;
                }
            }
        }
        return ele;
    }
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int dominant = findDominant(nums);
       // vector<int> freq(n, 0);

        //if(nums[0] == dominant) freq[0] = 1;
        int majCount = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == dominant) majCount++;
        }

        int countleft = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == dominant) countleft ++;
            int countright = majCount - countleft;

            if(countleft *2 > i+1 && countright*2 > n-i-1)
                return i;
        }
        return -1;
    }
};
