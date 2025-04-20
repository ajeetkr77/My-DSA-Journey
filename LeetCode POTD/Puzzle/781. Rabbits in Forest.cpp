class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();

        vector<int> ans(1000, 0);

        int rabbits = 0;

        for(int i = 0; i < n; i++){
            ans[answers[i]]++;
        }

        for(int i = 0; i < 1000; i++){
            if(ans[i]){

                float curr = ans[i] / (float)(i+1);

                int curr1 = ceil(curr);
                
                rabbits += (curr1 * (i+1));
            }
        }
        return rabbits;
    }
};
