    /* 4. Median of Two Sorted Arrays (https://leetcode.com/problems/median-of-two-sorted-arrays/description/):

    Given two sorted arrays nums1 and nums2 of size m and n respectively, 
    return the median of the two sorted arrays.

    The overall run time complexity should be O(log (m+n)). */

    // t.c.= O(m+n), s.c.= O(m+n), where m=nums1.size() and n=nums2.size()
    #include <bits/stdc++.h>
    using namespace std;

    class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            vector<int> n3;
            int i=0, j=0;
            while(i < nums1.size() and j < nums2.size()) {
                if(nums1[i] <= nums2[j]) n3.push_back(nums1[i++]);
                else n3.push_back(nums2[j++]);
            }
            while(i < nums1.size()) n3.push_back(nums1[i++]);
            while(j < nums2.size()) n3.push_back(nums2[j++]);

            if(n3.size()%2) return n3[n3.size()/2];
            else return (double)(n3[n3.size()/2] + n3[n3.size()/2 - 1]) / 2.0;
        }
    };
    int main() {
        vector<int> a = {1,2}, b = {3,4};
        Solution sol;
        double ans = sol.findMedianSortedArrays(a, b);
        cout << "the median of the two sorted arrays is: " << ans;
    
        return 0;
    }