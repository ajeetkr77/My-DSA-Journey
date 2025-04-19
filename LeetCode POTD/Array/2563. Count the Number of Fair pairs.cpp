********************************************************

  T C ~~ O(n^2)
  S C = O(1)

  *******************************************************


class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        multiset<int> ms;
        int n = nums.size();

        ms.insert(nums[0]);

        long long fairs = 0;

        for(int i = 1; i < n; i++){

            auto lb = ms.lower_bound(lower - nums[i]);

            auto up = ms.upper_bound(upper - nums[i]);

            //cout<<*lb<<" "<<*up<<endl;

            // Finding the number of elements between
  	        // the lb and up [lb, up)

            //cout<<distance(ms.begin(), lb)<<" "<<distance(ms.begin(), up)<<endl;

            fairs += distance(lb, up);

            ms.insert(nums[i]);
        }


        return fairs;
    }
};

*******************************************************************
T. C  = O(nlogn)
  S .  C = O (n)

****************************************************************

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
       // multiset<int> ms;
        int n = nums.size();

       // ms.insert(nums[0]);

       sort(nums.begin(), nums.end());
       vector<int> sorted;
       sorted.push_back(nums[0]);

        long long fairs = 0;

        for(int i = 1; i < n; i++){

            auto lb = lower_bound(sorted.begin(), sorted.end(), lower - nums[i]);

            auto up = upper_bound(sorted.begin(), sorted.end(), upper - nums[i]);

            //cout<<*lb<<" "<<*up<<endl;

            // Finding the number of elements between
  	        // the lb and up [lb, up)

            //cout<<distance(ms.begin(), lb)<<" "<<distance(ms.begin(), up)<<endl;

            fairs += distance(lb, up);

            sorted.push_back(nums[i]);

            //ms.insert(nums[i]);
        }


        return fairs;
    }
};
*********************************************************************

T C = O(nlogn)
S C = O(1)

***********************************************************************



class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
       // multiset<int> ms;
        int n = nums.size();

       // ms.insert(nums[0]);

       sort(nums.begin(), nums.end());
      // vector<int> sorted;
      // sorted.push_back(nums[0]);

        long long fairs = 0;

        for(int i = 1; i < n; i++){

            auto lb = lower_bound(nums.begin(), nums.begin() + i, lower - nums[i]);

            auto up = upper_bound(nums.begin(), nums.begin() + i, upper - nums[i]);

            //cout<<*lb<<" "<<*up<<endl;

            // Finding the number of elements between
  	        // the lb and up [lb, up)

            //cout<<distance(ms.begin(), lb)<<" "<<distance(ms.begin(), up)<<endl;

            fairs += distance(lb, up);

            //sorted.push_back(nums[i]);

            //ms.insert(nums[i]);
        }


        return fairs;
    }
};
