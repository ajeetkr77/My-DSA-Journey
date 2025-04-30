class Solution {
public:
    bool evenDigit(int num){
        int digit = 0;

        while(num != 0){
            digit++;
            num /= 10;
        }

        return (digit % 2 == 0) ? true : false;
    }

    int findNumbers(vector<int>& nums) {
        int n = nums.size();

        int count = 0;

        for(int i = 0; i < n; i++){
            if(evenDigit(nums[i]))
                count++;
        }

        return count;
    }
};

*****************************************
Approach 2 : using constant time
****************************************

  class Solution {
public:
    
    int findNumbers(vector<int>& nums) {
        int n = nums.size();

        int count = 0;

        for(int i = 0; i < n; i++){
            if((nums[i] >= 10 && nums[i] <= 99) || (nums[i] >= 1000 && nums[i] <= 9999)
                || (nums[i] == 100000))
                count++;
        }

        return count;
    }
};
