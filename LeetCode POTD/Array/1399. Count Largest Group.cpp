***********************************

  Naive Approach 

************************************

class Solution {
public:
    int countLargestGroup(int n) {
        map<int, int> mp;
        int maxSize = 1;

        for(int i = 1; i <= n; i++){
            int num = i;
            int sumDigit = 0;

            while(num != 0){
                sumDigit += num % 10;
                num /= 10;
            }

            mp[sumDigit]++;

            maxSize = max(maxSize, mp[sumDigit]);
        }

        int groups = 0;
        //cout<<maxSize<<endl;

        for(auto & it : mp){
            //cout<<it.first<<" "<<it.second<<endl;
            if(it.second == maxSize) groups++;
        }

        return groups;
    }
};
