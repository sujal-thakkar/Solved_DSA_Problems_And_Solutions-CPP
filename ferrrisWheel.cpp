/* Ferris Wheel (https://cses.fi/problemset/task/1090/):
There are n children who want to go to a Ferris wheel, and your task is to find a gondola for each child.
Each gondola may have one or two children in it, and in addition,
the total weight in a gondola may not exceed x. You know the weight of every child.

What is the minimum number of gondolas needed for the children? */

#include <bits/stdc++.h>
using namespace std;

int minimumGondola(vector<int>&children, int n, int x) {
    sort(children.begin(), children.end());
    int gondola = 0;
    int i = 0, j = n - 1;
    while (i <= j)
    {
        if (children[i] + children[j] <= x or i == j)
        {
            gondola++;
            i++;
            j--;
        }
        else if (children[i] + children[j] > x)
        {
            gondola++;
            j--;
        }
    }

    return gondola;
}
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> children(n);
    for (int i = 0; i < n; i++)
        cin >> children[i];
    
    int ans = minimumGondola(children, n, x);
    cout << ans;

    return 0;
}