#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = n - 1; i >= 1; i--)
    {
        int didSwap = 0;
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
                didSwap = 1;
        }
        if(didSwap == 1){
            break;
        }
        // cout << "Runs " << i << '\n';
    }
}
// Recursive Bubble Sort Algorithm -->
void recursiveBubbleSort(int arr[], int n) {
    if(n == 0) return;

    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
    recursiveBubbleSort(arr, n-1);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    recursiveBubbleSort(arr, n);
    for (int it : arr)
        cout << it << " ";
    return 0;
}