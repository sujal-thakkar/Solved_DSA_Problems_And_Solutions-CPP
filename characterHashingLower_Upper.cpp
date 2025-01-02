#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cout<<"enter string: ";
    cin >> s;
    //pre-computing(Hashing)
    int hashArr[256] = {0}; // If we combine all lower & upper-case characters the count would be 256 -->
    for (int i = 0; i < s.size(); i++)
    {
        hashArr[s[i]]++;
    }
    
    int q;
    cin >> q;
    while(q--) {
        char c;
        cin >> c;
        //fetching
        cout << hashArr[c] << endl;
    }
    return 0;
}