// Given a sorted array of integers and a target, find the index of the target using Binary Search

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findIndex(vector<int>& v, int target) { // Iterative Binary Search
        int l=0, r=v.size()-1;
        while(l<=r) {
            // int mid = (l + r) / 2; 
            // optimized way to calculate mid to prevent overflow of large ints
            int mid = l + (r-l)/2;
            if(v[mid] < target) l = mid+1;
            else if(v[mid] > target) r = mid-1;
            else return mid;
        }
        return -1;
    }

    int findIndexRecursive(vector<int>& v, int target, int l, int r) { // Recursive Binary Search
        if(l > r) return -1;
        int mid = l + (r-l)/2;
        if(target < v[mid]) return findIndexRecursive(v, target, l, mid-1);
        else if(target > v[mid]) return findIndexRecursive(v, target, mid+1, r);
        else return mid;
    }
};
int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    int target;
    cin>>target;
    Solution sol;
    int ans = sol.findIndexRecursive(v, target, 0, n-1);
    cout << "ans: "<<ans;
 
    return 0;
}