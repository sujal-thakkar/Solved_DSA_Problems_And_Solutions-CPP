/* Binary Searchable Elements

The problem is that given an array containing unique integers,
you need to find the number of array elements which can be
searched using the binary search algorithm shown in the
previous slide. */

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int beg = 0, end = n - 1;
    int ans = -1;
    while (beg <= end) {
        int mid = beg + (end - beg) / 2;
        if (arr[mid] == target) {
            ans = arr[mid];
            break;
        } else if (arr[mid] > target) {
            end = mid - 1;
        } else {
            beg = mid + 1;
        }
    }
    return ans;
}
vector<int> searchableElementsUsingBS(int arr[], int n) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (binarySearch(arr, n, arr[i]) != -1)
            ans.push_back(arr[i]);
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> ans = searchableElementsUsingBS(arr, n);
    int noOfSearchbleEle = 0;
    cout << "elements which can be searched by Binary search, are: ";
    for (int i=0; i<ans.size(); i++) {
        noOfSearchbleEle++;
        cout << ans[i] << " ";
    }
    
 
    return 0;
}