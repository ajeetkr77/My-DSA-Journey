class Solution {
public:
    int differenceOfSums(int n, int m) {
        
        int num1 = (n * (n + 1)) / 2;
        int k = 1;

        cout<<num1<<endl;
        while(m * k <= n){
            num1 -= 2*m*k;
            //cout<<m * k<<" "<<num1<<endl;
            k++;
        }

        return num1;
    }
};
