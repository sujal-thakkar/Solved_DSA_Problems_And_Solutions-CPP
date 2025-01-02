#include <bits/stdc++.h>
using namespace std;

bool isSNgreater(int mid) {
    int SN = 273;

    if (SN > mid)
        return true;

    return false;
}
int findSecretNumber(int l, int r) {
    if (l == r)
        return l;

    int mid = (l + r) / 2;

    bool checkForGreater = isSNgreater(mid);

    if (checkForGreater) {
        cout << "the number is b/w " << mid << " & " << r << endl;
        return findSecretNumber(mid + 1, r);
    }

    cout << "The number is b/w " << l << " & " << mid << endl;
    return findSecretNumber(l, mid);
}
int main() {
    int l = 1;
    int r = 500000;
    cout << "the range is " << l << " to " << r << endl;
    int ans = findSecretNumber(l, r);
    cout << "The mother-fucking number is: " << ans;

    return 0;
}