class Solution {
public:
    void solve(int start, vector<int> &result, int n){

        if(start > n) return ;

        result.push_back(start);

        for(int append = 0; append <= 9; append++){

            int startAppend = start * 10 + append;

            if(startAppend > n) return;

            solve(startAppend, result, n);
        }
    }

    vector<int> lexicalOrder(int n) {
        
        vector<int> result;

        for(int start = 1; start <= 9; start++){
            solve(start, result, n);
        }

        return result;
    }
};
