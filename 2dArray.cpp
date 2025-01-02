#include <bits/stdc++.h>
using namespace std;

int main()
{
    int count = 1;
    int two_d[4][4];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            two_d[i][j] = count;
            count++;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << two_d[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}