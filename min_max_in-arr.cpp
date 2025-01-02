#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> getMinMax(vector<long long int> arr)
{

    // this method will be more efficient for larger array sizes,
    // although the T.C. and S.C. remaiins same but it'll be optimized
    // in the basis of comparison b/w the elements. which will take 3n/2 comparisons
    // whereas, previously we were doing it with 2n times.

    if (arr.empty())
        return {0, 0};

    long long min = arr[0];
    long long max = arr[0];

    for (long long i = 1; i < arr.size(); i += 2)
    {
        if (i + 1 < arr.size())
        {
            if (arr[i] < arr[i + 1])
            {
                if (arr[i] < min)
                    min = arr[i];
                if (arr[i + 1] > max)
                    max = arr[i + 1];
            }
            else
            {
                if (arr[i] > max)
                    max = arr[i];
                if (arr[i + 1] < min)
                    min = arr[i + 1];
            }
        }
        else
        {
            if (arr[i] < min)
                min = arr[i];
            else if (arr[i] > max)
                max = arr[i];
        }
    }

    return {min, max};
}

int main()
{
    vector<long long int> arr = {3, 2, 1, 56, 1000, 167};
    getMinMax(vector<long long int> arr);

    return 0;
}