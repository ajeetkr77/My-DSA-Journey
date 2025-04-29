class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        int n = nums.size();
        
        int majEle1, majEle2;
        
        int count1=0, count2 = 0;
        
        // Assumption
        
        for(int i = 0; i < n; i++){
            if(nums[i] == majEle1){
                count1++;
            }else if(nums[i] == majEle2){
                count2++;
            }else if(count1 == 0){
                majEle1 = nums[i];
                count1 = 1;
            }else if(count2 == 0){
                majEle2 = nums[i];
                count2 = 1;
            }else{
                count1 --, count2--;
            }
        }
        
        // Verification
        
        count1 = 0, count2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == majEle1){
                count1++;
            }
            if(nums[i] == majEle2){
                count2++;
            }
        }
        
        vector<int> ans;
        
        if(count1 > n / 3) ans.push_back(majEle1);
        
        if(count2 > n / 3) ans.push_back(majEle2);
        
        sort(ans.begin(), ans.end());
        
        return ans;
        
    }
};
