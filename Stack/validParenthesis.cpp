#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int openCnt = 0;
    int closeCnt = 0;
    if(s[0] == ')') {
        cout << "Not valid";
        return 0;
    }

    for(int i=1; i<s.size(); i++) {
        if(s[i] == '(') openCnt++;
        else closeCnt++;
    }
    if(openCnt == closeCnt) cout << "valid";
    else cout << "Not valid";
 
    return 1;
}