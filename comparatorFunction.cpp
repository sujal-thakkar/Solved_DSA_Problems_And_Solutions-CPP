#include <bits/stdc++.h>
using namespace std;

bool swappable(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first) {
        if(a.first > b.first) return true;
        else return false;
    } else {
        if(a.second > b.second) return true;
    }
    return false;
}

int main() {

    int n;
    cin >> n;
    vector<pair<int, int>> vec(n);
    cout << "Input:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> vec[i].first >> vec[i].second;
    }

    /* for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (swappable(vec[i], vec[j])) {
                swap(vec[i], vec[j]);
            }
        }
    } */
   sort(vec.begin(), vec.end(), swappable);

    cout << "Output:" << endl;
    for (int i = 0; i < n; i++) {
        cout << vec[i].first << " " << vec[i].second << endl;
    }

    return 0;
}