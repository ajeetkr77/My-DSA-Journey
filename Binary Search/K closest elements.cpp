class Solution {
  public:
    int justGreaterX(vector<int> &arr, int x, int n){
        
        int l = 0, r = n - 1;
        
        int index = -1;
        while(l <= r){
            
            int mid = (l + r) / 2;
            
            if(arr[mid] < x){
                l = mid + 1;
                index = mid;
            }else{
                r = mid - 1;
            }
        }
        
        return index;
    }
    
    int justSmallerX(vector<int> &arr, int x, int n){
        
        int l = 0, r = n - 1;
        
        int index = -1;
        while(l <= r){
            
            int mid = (l + r) / 2;
            
            if(arr[mid] < x){
                l = mid + 1;
            }else{
                r = mid - 1;
                index = mid;
            }
        }
        
        return index;
    }
    
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // Code here
        
        int index = -1;
        
        int n = arr.size();
        
        vector<int> ans;
        
        int l = 0, r = n - 1;
        
        while(l <= r){
            
            int mid = (l + r) / 2;
            
            if(arr[mid] == x){
                index = mid;
                break;
            }
            else if(arr[mid] > x)
                r = mid - 1;
            else
                l = mid + 1;
        }
        
        int i, j;
        
        if(index == -1){
            int nextGreater = justGreaterX(arr, x, n);
            int nextSmaller = justSmallerX(arr, x, n);
            
           // cout<<nextGreater<<" "<<nextSmaller<<" ";
            
            if(nextGreater == -1){
                index = nextSmaller;
                k--;
                ans.push_back(arr[index]);
            }
                
            
            if(nextSmaller == -1){
                index = nextGreater; 
                k--;
                ans.push_back(arr[index]);
            }
                
            if(nextSmaller != -1 && nextGreater != -1){
                i = nextGreater, j = nextSmaller; 
            }
        }
        
        
        if(index != -1){
            i = index - 1, j = index + 1;
        }
        
        while( i >= 0 && j < n && k > 0){
            
            int left = abs(arr[i] - x);
            
            int right = abs(arr[j] - x);
            
            if(left < right){
                ans.push_back(arr[i]);
                i--;
            }else if(right < left){
                ans.push_back(arr[j]);
                j++;
            }else{
                if(arr[i] > arr[j]){
                    ans.push_back(arr[i]);
                    i--;
                }else{
                    ans.push_back(arr[j]);
                    j++;
                }
            }
            
            k--;
        }
        
        while(i >= 0 && k > 0){
            ans.push_back(arr[i]);
            i--, k--;
        }
        
        while(j < n && k > 0){
            ans.push_back(arr[j]);
            j++, k--;
        }
        
        return ans;
    }
};
