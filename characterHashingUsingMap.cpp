#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    // pre-compute;
    map<char, int> mpp;
    for (int i = 0; i < s.size(); i++)
    {
        mpp[s[i]]++;
    }

    for(auto it : mpp)
        cout << it.first << " --> " << it.second << endl; // map store items in a key-value pair and the items stored will always be in
                                                         // a sorted manner no matter how it's provided input: cedfagb, stores: abcdefg;

    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        // fetch;
        // cout << mpp[c] << endl;
    }
    return 0;
}