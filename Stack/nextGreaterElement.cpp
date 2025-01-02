#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n) {
        // Your code here
        if (arr.size() == 1)
            return {-1};
        vector<long long> ans;
        for (long long i = 0; i < arr.size(); i++) {
            int flag = 0;
            for (long long j = i; j < arr.size(); j++) {
                if (arr[j] > arr[i]) {
                    ans.push_back(arr[j]);
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                ans.push_back(-1);
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution obj;
        vector<long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}