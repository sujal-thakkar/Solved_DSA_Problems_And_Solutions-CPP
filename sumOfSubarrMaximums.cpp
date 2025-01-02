/* 907. Sum of Subarray Maximums:

Given an array of integers arr, find the sum of max(b), 
where b ranges over every (contiguous) subarray of arr. 
Since the answer may be large, return the answer modulo 10^9 + 7.

Input: arr = [3,1,2,4]
Output: 30
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 3, 2, 4, 3, 4, 4
Sum is 30.

Constraints:
1 <= arr.length <= 3 * 10^4
1 <= arr[i] <= 3 * 10^4 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n), pge(n);
        stack<int> st;
        int sum = 0;
        int mod = 1e9 + 7;

        for(int i=n-1; i>=0; i--) { // 3 1 2 4
            while(!st.empty() and arr[st.top()] <= arr[i]) {
                st.pop();
            }
            if(st.empty()) {
                nge[i] = n - i;
            }
            else {
                nge[i] = st.top() - i;
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=0; i<n; i++) {
            while(!st.empty() and arr[st.top()] <= arr[i]) {
                st.pop();
            }
            if(st.empty()) {
                pge[i] = i - (-1);
            }
            else {
                pge[i] = i - st.top();
            }
            st.push(i);

            sum = (sum + (long long)arr[i] * nge[i] * pge[i]) % mod;
        }
        return sum;
    }
};
int main() {
    Solution sol;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int ans = sol.sumSubarrayMaxs(arr);
    cout << "ans: " << ans;
 
    return 0;
}