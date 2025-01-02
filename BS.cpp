#include <bits/stdc++.h>
using namespace std;

boolean findTarget(int arr[], int n, int target) {
    int beg = 0, end = n - 1;
    while (beg <= end) {
        int mid = (beg + end) / 2;
        if (arr[mid] == target)
            return true;
        else if (arr[mid] > target)
            end = mid - 1;
        else
            beg = mid + 1;

        return false;
    }
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    if (findTarget(arr, n, target))
        cout << "Present!";
    else
        cout << "Not Present!";
    return 0;
}