*****************************************************
Brute Force , TLE

*****************************************************


class Solution {
public:
    bool check(vector<int>& nums, int i, int j, int dis){
        unordered_set<int> st;

        for(int k = i; k <=j; k++)
            st.insert(nums[k]);
        
        return (st.size() == dis);

    }

    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st;

        for(int i = 0; i < n; i++) st.insert(nums[i]);

        int distinct = st.size(), ans = 0;

        cout<<distinct<<endl;

        for(int i = 0; i < n; i++){

            for(int j = i; j < n; j++){

                if(check(nums, i, j, distinct)) 
                    ans++;
            }
        }

        return ans;
    }
};


************************************************************
Optimal Approach : Sliding Windows O(N)

************************************************************

  int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;

        for(int i = 0; i < n; i++) st.insert(nums[i]);

        int distinct = st.size(), ans = 0;

        map<int, int> mp;

        int i = 0, j = 0;

        while(j < n){
            mp[nums[j]]++;

            while(mp.size() == distinct){
                ans += n - j;
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        

        return ans;
    }
