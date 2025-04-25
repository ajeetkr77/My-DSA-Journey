****************************************
  Solution using two iteration

  Using two pointer 

  1. Increase j keep i constant
  2. if arr[j] != 0 , put this at ith index
  3. if arr[j] == 0, count it 
  4. append zero at the end as many times zero comes

*********************************************
Solution using one iteration

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int i = 0, j = 0;
        int cnt = 0;
        
        while( j < n ){
            if(arr[j] == 0 && cnt == 0){
                i = j;
                cnt++;
            }
            else if(arr[j] == 0 && cnt != 0)
                cnt++;
            
            else if(arr[j] != 0 && cnt > 0){
                swap(arr[i], arr[j]);
                i++;
                cnt--;
                if(arr[i] == 0 && cnt == 0)
                    cnt++;
            }
            j++;
        }
        
    }
};
