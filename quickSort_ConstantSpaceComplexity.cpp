#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = low;

    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= arr[pivot] and i < high)
            i++;

        while (arr[j] > arr[pivot] and j > low)
            j--;

        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    swap(arr[j], arr[pivot]);

    return pivot;
}

void quickSort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int partitionIndex = partition(arr, low, high);

    quickSort(arr, low, partitionIndex - 1);
    quickSort(arr, partitionIndex + 1, high);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(arr, 0, n - 1);

    for (int i : arr)
        cout << i << " ";
    return 0;
}