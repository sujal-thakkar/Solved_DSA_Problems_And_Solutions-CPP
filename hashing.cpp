#include <bits/stdc++.h>
using namespace std;

int main()
{
    int hashArr[53] = {0};

    int arr[53]={4, 5, 2, 4, 52, 9};
    for(int i=0; i<53; i++) {
        hashArr[arr[i]] += 1;
    }

    int q; cin >> q;
    int number;
    while(q--) {
        cin >> number;
    }
    cout << hashArr[number] << endl;
    
    return 0;
}