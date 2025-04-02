******************************* Brute Force Approach *****************************
                      T.C : O(N)
                      S.C : O(N)
**********************************************************************************
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<int> temp(m+n);
        int i = 0, j = 0, k = 0;

        while(i < m && j < n){
            if(nums1[i] < nums2[j]){
                temp[k++] = nums1[i++];
            }else
                temp[k++] = nums2[j++];
        }

        while(i < m){
            temp[k++] = nums1[i++];
        }
        while(j < n){
            temp[k++] = nums2[j++];
        }

        if((m+n) % 2 == 0) return (temp[(m+n)/2] + temp[(m+n)/2 - 1]) / 2.0;
        return temp[(m+n)/2];
    }
};

******************************* Better Approach *****************************
                  T.C : O(N)
                  S.C : O(1)
*****************************************************************************

  class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int i = 0, j = 0, k = 0;

        int idx1 = (m + n) / 2;
        int idx2 = idx1 - 1;

        int ele1 , ele2;

        while(i < m && j < n){
            if(nums1[i] < nums2[j]){
                if(k == idx1) ele1 = nums1[i];
                if(k == idx2) ele2 = nums1[i];
                i++;
            }else{
                if(k == idx1) ele1 = nums2[j];
                if(k == idx2) ele2 = nums2[j];
                j++;
            }
            k++;    
        }

        while(i < m){
            if(k == idx1) ele1 = nums1[i];
            if(k == idx2) ele2 = nums1[i];
            i++; k++;
        }
        while(j < n){
            if(k == idx1) ele1 = nums2[j];
            if(k == idx2) ele2 = nums2[j];
            j++; k++;
        }

        cout<<ele2<<" "<<ele1<<endl;

        if((m+n) % 2 == 0) return (ele1 + ele2) / 2.0;
        return ele1;
    }
};

***************************** Optimal Approach *************************
T.C: O(log(min(m,n)))
S.C: O(1)
************************************************************************
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int l = 0, r = m;

        while(l <= r){
            int Px = l + (r - l) / 2;
            int Py = (m+n+1)/2 - Px;

            // left half 

            int x1 = (Px == 0) ? INT_MIN : nums1[Px - 1];
            int x2 = (Py == 0) ? INT_MIN : nums2[Py - 1];

            // right half

            int x3 = (Px == m) ? INT_MAX : nums1[Px];
            int x4 = (Py == n) ? INT_MAX : nums2[Py];

            if(x1 <= x4 && x2 <= x3){
                if((m + n) % 2 == 0){
                    return (max(x1,x2) + min(x3, x4))/ 2.0;
                }
                return max(x1, x2);
            }else if(x1 > x4){
                r = Px - 1;
            }else{
                l = Px + 1;
            }

        }
        return -1;
    }
};
  
