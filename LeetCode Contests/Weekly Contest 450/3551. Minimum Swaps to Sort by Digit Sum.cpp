class Solution {
public:
    static bool Compare(const pair<int,int> &a, const pair<int,int> &b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first < b.first;
    }

    
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int,int>> arr, brr;
        map<pair<int, int> , int> pos;

        for(int i = 0; i < n; i++){
            int x = nums[i];

            int sum = 0;

            while(x != 0){
                sum += (x % 10);
                x /= 10;
            }
            arr.push_back({sum, nums[i]});
            brr.push_back({sum, nums[i]});
            pos[{sum, nums[i]}] = i;
        }


        sort(arr.begin(), arr.end(), Compare);

        // for(int i = 0; i < n; i++){
        //     cout<<arr[i].first<<" "<<arr[i].second<<" ";
        // }
        // cout<<endl;

        // for(int i = 0; i < n; i++){
        //     cout<<brr[i].first<<" "<<brr[i].second<<" ";
        // }

        int minSwap = 0;

        for(int i = 0; i < n; i++){
            if(arr[i].first != brr[i].first || arr[i].second != brr[i].second){
                minSwap++;

                int ind = pos[arr[i]];
                swap(brr[i], brr[ind]);

                pos[brr[i]] = i;
                pos[brr[ind]] = ind;
            }
        }

        return minSwap;
    }
};


***********************************************

Approach 2 using Cycle detection Similar q on gfg



class Solution {
  public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& arr) {
        // Code here
        int n = arr.size();
        
        vector<int> temp(arr.begin(), arr.end());
        
        sort(temp.begin(), temp.end());
        
        unordered_map<int, int> pos;
        
        for(int i = 0; i < n; i++) pos[temp[i]] = i;
        
        temp = arr;
        
        for(int i = 0; i < n; i++) temp[i] = pos[temp[i]];
        
        int ans = n; 
        
        vector<int> vis(n, 0);
        
        for(int i = 0; i < n; i++){
            
            if(vis[i]) continue;
            
            int j = i;
            
            while(!vis[j]){
                
                vis[j] = 1;
                j = temp[j];
                
            }
            ans --;
        }
        
        return ans;
    }
};


