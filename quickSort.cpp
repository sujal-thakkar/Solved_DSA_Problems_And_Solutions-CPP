#include <bits/stdc++.h>
using namespace std;

int partitionIndex(int arr[], int l, int r)
{
    int pivotElement = arr[r];

    vector<int> smaller;
    vector<int> larger;

    for (int i = l; i < r; i++)
    {
        if (arr[i] <= pivotElement)
        {
            smaller.push_back(arr[i]);
        }
        else
        {
            larger.push_back(arr[i]);
        }
    }

    // put the elements from smaller and larger to the main array to be able to have a sorted array -->
    int id = l;
    for (int i = 0; i < smaller.size(); i++)
    {
        arr[id] = smaller[i];
        id++;
    }

    arr[id] = pivotElement;
    int pivotIndex = id;
    id++;

    for (int i = 0; i < larger.size(); i++)
    {
        arr[id] = larger[i];
        id++;
    }

    return pivotIndex;
}

void quickSort(int arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }

    int id = partitionIndex(arr, l, r);

    quickSort(arr, l, id - 1);
    quickSort(arr, id + 1, r);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    for (auto it : arr)
    {
        cout << it << " ";
    }

    return 0;
}