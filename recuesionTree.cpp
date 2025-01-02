#include <bits/stdc++.h>
using namespace std;

int power(int a, int n)
{
    if (n == 0)
        return 1;

    if (n % 2 == 0)
        return power(a, n / 2) * power(a, n / 2);

    return power(a, n / 2) * power(a, n / 2) * a;
}

int main()
{
    cout << power(2, 4);

    return 0;
}