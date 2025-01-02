#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cout << "enter string: ";
    cin >> s;
    // pre compute
    int hashArr[25] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        hashArr[s[i] - 'a']++;
    }
    int q;
    cout << "enter query number: ";
    cin >> q; cout << endl;
    while (q--)
    {
        char c;
        cout << "enter character: ";
        cin >> c;
        // fetch
        cout << "the character " << c << " has frequency of: ";
        cout << hashArr[c - 'a'] << endl << endl;
    }
    return 0;
}