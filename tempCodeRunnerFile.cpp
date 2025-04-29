#include <bits/stdc++.h>
using namespace std;

void iterativePrint(int n) {
    for(int i=n; i>0; i--) cout << i << " ";
}
void recursivePrint(int n) {
    if(n==1) {
        cout << n;
        return;
    }
    cout << n << " ";
    recursivePrint(n-1);
}

int nFactorialIterative(int n) {
    int ans = 1;
    for(int i=n; i>0; i--) ans *= i;
    return ans;
}
int nFactorialRecursive(int n) {
    if(n == 0) return 1;
    return n * nFactorialRecursive(n-1);
}

int sumOfNIterative(int n) {
    int ans = 0;
    for(int i=1; i<=n; i++) ans += i;
    return ans;
}
int sumOfNRecursive(int n) {
    if(n == 1) return 1;
    return n + sumOfNRecursive(n-1);
}

int findNthFibonacciTermIterative(int n) {
    int first = 0, sec = 1;
    for(int i=2; i<n; i++) {
        int temp = first;
        first = sec;
        sec += temp;
    }
    return first + sec;
}
int findNthFibonacciTermRecursive(int n) {
    if(n == 0 or n == 1) return n;
    return findNthFibonacciTermRecursive(n-1) + findNthFibonacciTermRecursive(n-2); 
}

bool isSortedIterative(vector<int>& v) {
    for(int i=0; i<v.size(); i++) if(i != 0 and v[i] <= v[i-1]) return false;
    return true;
}
bool isSortedRecursive(vector<int>& v, int n) {
    if(n == 1) return true;
    return (v[n-1] >= v[n-2] and isSortedRecursive(v, n-1));
}

int findTargetIterative(vector<int>& v, int target) {
    int l=0, r=v.size()-1;
    while(l <= r) {
        int m = l + (r-l)/2;
        if(v[m] < target) l = m+1;
        else if(v[m] > target) r = m-1;
        else return m;
    }
}
int findTargetRecursive(vector<int>& v, int target, int l, int r) {
    if(l > r) return -1; // base case

    int m = l + (r-l)/2;
    if(v[m] < target) return findTargetRecursive(v, target, m+1, r);
    else if(v[m] > target) return findTargetRecursive(v, target, l, m-1);
    else return m;
}

int main() {
    // recursivePrint(5);
    // cout << nFactorialIterative(9);
    // cout << nFactorialRecursive(5);
    // cout << sumOfNIterative(5);
    // cout << sumOfNRecursive(5);
    // cout << findNthFibonacciTermRecursive(13); // 1 5 8 9 7
    vector<int> v = {0, 2, 3, 4, 5, 9, 100, 122, 1500};
    // isSortedRecursive(v, v.size())? cout << "Sorted" : cout << "Not Sorted";
    cout << findTargetRecursive(v, 100, 0, v.size()-1);
 
    return 0;
}