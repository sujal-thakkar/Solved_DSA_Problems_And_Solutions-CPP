#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int modifiedBinarySearchSearchableElements(vector<int> &arr, int n) {
        int preMax[n];
        int sufMin[n];

        for (int i = 0; i < n; i++) {
            preMax[i] = (i == 0) ? arr[i] : max(preMax[i - 1], arr[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            sufMin[i] = (i == n - 1) ? arr[n - 1] : min(arr[i], sufMin[i + 1]);
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            int leftMax = (i == 0) ? INT_MIN : preMax[i - 1];
            int rightMin = (i == n - 1) ? INT_MAX : sufMin[i + 1];

            if (arr[i] > leftMax and arr[i] < rightMin) {
                count++;
            }
        }
        return count;
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Solution sol;
    int ans = sol.modifiedBinarySearchSearchableElements(arr, n);
    cout << "searchable elements: " << ans;

    return 0;
}