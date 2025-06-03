**********************************************
  Naive Approach : O(n^2)
**********************************************


class Solution {
  public:
  
    bool canPlaceCow(vector<int> &stalls, int k, int dist){
        
        int countCows = 1, lastCordCow = stalls[0];
        
        for(int i = 1; i < stalls.size(); i++){
            
            if(stalls[i] - lastCordCow >= dist){
                countCows++;
                lastCordCow = stalls[i];
            }
            
            if(countCows >= k){
                //cout<<countCows<<endl;
                return true;
            } 
        }
        
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        int n = stalls.size();
        
        sort(stalls.begin(), stalls.end());
        
        int maxDist2Cow = stalls[n-1] - stalls[0];
        
        for(int i = 1; i <= maxDist2Cow + 1; i++){
            
            if(canPlaceCow(stalls, k, i)) continue;
            
            else 
                return i - 1;
        }
        
        return -1;
    }
};

*******************************************************
  Optimal Approach: O(nLogn)
*******************************************************

class Solution {
  public:
  
    bool canPlaceCow(vector<int> &stalls, int k, int dist){
        
        int countCows = 1, lastCordCow = stalls[0];
        
        for(int i = 1; i < stalls.size(); i++){
            
            if(stalls[i] - lastCordCow >= dist){
                countCows++;
                lastCordCow = stalls[i];
            }
            
            if(countCows >= k){
                //cout<<countCows<<endl;
                return true;
            } 
        }
        
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        int n = stalls.size();
        
        sort(stalls.begin(), stalls.end());
        
        int minDist2Cow = 1, maxDist2Cow = stalls[n-1] - stalls[0] + 1;
        
        int ans ;
        
        while(minDist2Cow <= maxDist2Cow){
            
            int mid = ( minDist2Cow + maxDist2Cow ) / 2;
            
            if(canPlaceCow(stalls, k, mid)){
                ans = mid;
                minDist2Cow = mid + 1;
            }else{
                maxDist2Cow = mid - 1;
            }
            
        }
        
        return ans;
    }
};
