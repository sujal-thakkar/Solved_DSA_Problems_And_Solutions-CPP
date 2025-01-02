// Plus or Minus (https://codeforces.com/problemset/problem/1807/A):
// You are given three integers a, b, and c
// such that exactly one of these two equations is true:

// a+b=c
// a−b=c
// Output + if the first equation is true, and - otherwise.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;

    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;

        if(a+b == c)
            cout << "+" << endl;
        else if(a-b == c)
            cout << "-" << endl;
    }
    return 0;
}