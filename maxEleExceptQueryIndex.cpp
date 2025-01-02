// given an array and M queries, each query will have an index i ,
// we need to find maximum from all the array element
// except the element of a[i].
// there is an array M which have multiple queries that refers to a index number.
// we have to find the max element excluding the indexed element given, everytime.

#include <bits/stdc++.h>
using namespace std;

int findMaxExceptI(const vector<int> &arr, int i)
{
    int max_val = INT_MIN; // Initialize with negative infinity
    for (int j = 0; j < arr.size(); ++j)
    {
        if (j != i)
        {
            max_val = max(max_val, arr[j]);
        }
    }
    return max_val;
}

int main()
{
    vector<int> array = {2, 1, 3, 5, 4, 5, 7, 6};
    vector<int> queries = {4, 7, 6, 3}; // Example query indices
    for (int query_index : queries)
    {
        int result = findMaxExceptI(array, query_index);
        cout << "Maximum value (excluding element at index " << query_index << "): " << result << endl;
    }
    return 0;
}