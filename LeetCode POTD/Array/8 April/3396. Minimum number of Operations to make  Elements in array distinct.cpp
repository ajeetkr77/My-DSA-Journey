
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int minOp = 0;
        while(true){
            int n = nums.size();
            bool isDistinct = true;
            unordered_map<int, int> mp;
            for(int i = 0; i < n; i++){
                if(mp[nums[i]] > 0){
                    isDistinct = false;
                    break;
                }
                mp[nums[i]]++;
            }

            if(isDistinct) break;

            if(nums.size() > 3)
                nums.erase(nums.begin(), nums.begin() + 3);
            else
                nums.erase(nums.begin(), nums.end());
            // for(int i = 0; i <nums.size(); i++) cout<<nums[i]<<" ";
            // cout<<endl;
            minOp++;
        }
        return minOp;
    }
};
