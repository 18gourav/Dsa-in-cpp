// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n,
//  representing the number of elements in nums1 and nums2 respectively.
// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> num3;
        int i=0;
        int j=0;

        while(i<m && j<n ){
            if(nums1[i] < nums2[j]){
                    num3.push_back(nums1[i]);
                    i++;
                }
                else {
                       num3.push_back(nums2[j]);
                       j++;
                }  
        }

         while (i < m) {
            num3.push_back(nums1[i]);
            i++;
        }

        // Copy leftover elements of nums2
        while (j < n) {
            num3.push_back(nums2[j]);
            j++;
        }

        // Copy merged result back into nums1
        for (int k = 0; k < m + n; k++) {
            nums1[k] = num3[k];
        }

    }
};