#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec = {1, 0, 1, 0, 2, 9, 8};
    int small = INT_MAX;
    int small2 = INT_MAX;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] < small)
        {
            small2 = small;
            small = vec[i];
        }
        else if (vec[i] > small and vec[i] < small2)
        {
            small2 = vec[i];
        }
    }
    if (small2 == INT_MAX)
        cout << -1;
    cout << "smallest- " << small << endl;
    cout << "sec_smallest- " << small2;
    return 0;
}