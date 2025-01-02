#include <bits/stdc++.h>
using namespace std;
// using 1 pointer -->
void f(int arr[], int i, int n)
{
    if (i >= n / 2)
        return;
    swap(arr[i], arr[n - i - 1]);
    f(arr, i + 1, n);
}

int main()
{
    int n;
    cin >> n;
    int i = 0;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    f(arr, i, n);
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    return 0;
}