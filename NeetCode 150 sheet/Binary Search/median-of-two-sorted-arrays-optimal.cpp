    /* 4. Median of Two Sorted Arrays (https://leetcode.com/problems/median-of-two-sorted-arrays/description/):

    Given two sorted arrays nums1 and nums2 of size m and n respectively, 
    return the median of the two sorted arrays.

    The overall run time complexity should be O(log (m+n)). */
    
    // t.c.= O(log(m+n)), t.c.= O(1), where m = nums1.size(), and n = nums2.size();
    #include <bits/stdc++.h>
    using namespace std;

    class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) { //n1 = [1 5 9 12] n2 = [7 10 18 15]
            int n1 = nums1.size(), n2 = nums2.size();// 1 5, 7 10 | 9 12, 18 15
            int n = n1 + n2;
            if(n1 > n2) return findMedianSortedArrays(nums2, nums1);
            int leftEleSize = (n + 1) / 2;
            int l=0, r=n1;
            while(l <= r) {
                int mid1 = l + (r-l)/2;
                int mid2 = leftEleSize - mid1;
                int l1 = INT_MIN, l2 = INT_MIN;
                int r1 = INT_MAX, r2 = INT_MAX;
                if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
                if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1];
                if(n1 > mid1) r1 = nums1[mid1];
                if(n2 > mid2) r2 = nums2[mid2];
                if(l1 > r2) r = mid1 - 1;
                else if(l2 > r1) l = mid1 + 1;
                else return (n % 2)? (double)max(l1, l2) : (double)(max(l1, l2) + min(r1, r2)) / 2.0;
            }
            return 0.0;
        }
    };
    int main() {
        vector<int> a = {1,2}, b = {3,4};
        Solution sol;
        double ans = sol.findMedianSortedArrays(a, b);
        cout << "the median of the two sorted arrays is: " << ans;
    
        return 0;
    }