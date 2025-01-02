#include <bits/stdc++.h>
using namespace std;
// Using 2 pointers, one at 0th and one at last -->
void reversedArr(vector<int> &arr, int l, int r) {
    if (l >= r)
        return;

    swap(arr[l], arr[r]);

    reversedArr(arr, l + 1, r - 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int l = 0;
    int r = arr.size() - 1;
    reversedArr(arr, l, r);

    cout << "Reversed: ";
    for (int i : arr) {
        cout << i << " ";
    }
    return 0;
}