// Common in 3 Sorted Arrays (https://www.geeksforgeeks.org/problems/common-elements1132/1):

// Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
// Note: can you take care of the duplicates without using any additional Data Structure?

#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    vector<int> commonElements(int a[], int b[], int c[], int n1, int n2, int n3) {

        vector<int> ans;

        int i = 0, j = 0, k = 0;

        while(i < n1 and j<n2 and k<n3) {
            if(a[i] == b[j] and a[i] == c[k]) {
                if(ans.empty() || ans.back() != a[i])
                    ans.push_back(a[i]);
            }
            else if(a[i] < b[j])
                i++;
            else if(b[j] < c[k])
                j++;
            else
                k++;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    int n1 = 3, n2 = 5, n3 = 2;
    int a[n1] = {3,3,3};
    int b[n2] = {2, 3, 6, 8, 10};
    int c[n3] = {3,9};

    // vector<int> ans = sol.commonElements(a[n1], b[n2], c[n3], n1, n2, n3);

    
    return 0;
}