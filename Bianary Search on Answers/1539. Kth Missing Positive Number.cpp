class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int n = arr.size();
        int low = 0, high = n - 1;

        while(low <= high){
            int mid = (low + high) / 2;

            // Missing = What is actually present - what ideally should be present

            int missing = arr[mid] - (mid + 1);

            if(missing < k) low = mid + 1;

            else
                high = mid - 1;
        }

        // we need to return arr[high] + more 
        // more = k - missing
        // missing = arr[high] - (high + 1)
        // arr[high] + k - arr[high] + high + 1

        return k + high + 1;
    }
};
