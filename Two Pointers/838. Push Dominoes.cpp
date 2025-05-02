class Solution {
public:
    string pushDominoes(string dominoes) {

        int len = dominoes.length();

        vector<int> leftClosestR(len), rightClosestL(len);

        string result = "";

        for(int i = 0; i < len; i++){
            if(dominoes[i] == 'L'){
                leftClosestR[i] = -1;
            }else if(dominoes[i] == 'R'){
                leftClosestR[i] = i;
            }else{
                leftClosestR[i] = (i == 0) ? -1 : leftClosestR[i-1];
            }
        }

        for(int i = len - 1; i >= 0; i--){
            if(dominoes[i] == 'R'){
                rightClosestL[i] = -1;
            }else if(dominoes[i] == 'L'){
                rightClosestL[i] = i;
            }else{
                rightClosestL[i] = (i == len - 1) ? -1 : rightClosestL[i+1];
            }
        }

        for(int i = 0; i < len; i++){

            int disLeftClosestR = abs(i - leftClosestR[i]);
            int disRightClosestL = abs(i - rightClosestL[i]);

            if(leftClosestR[i] == rightClosestL[i]){
                result += '.';
            }else if(leftClosestR[i] == -1){
                result += 'L';
            }else if(rightClosestL[i] == -1){
                result += 'R';
            }else if(disLeftClosestR == disRightClosestL){
                result += '.';
            }else{
                char ch = (disLeftClosestR < disRightClosestL) ? 'R' : 'L';
                result += ch;
            }
        }

        return result;
    }
};
