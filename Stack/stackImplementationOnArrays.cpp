#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    int arr[1000];
    int len;

    MyStack() {
        len = -1;
    }

    int top() {
        if (len == -1)
            return -1;
        return arr[len];
    }
    void push(int x) {
        len++;
        arr[len] = x;
    }
    int pop() {
        if (len == -1)
            return -1;
        int poppedEle = arr[len];
        len--;
        return poppedEle;
    }
    bool empty() {
        if (len == -1)
            return true;
        else
            return false;
    }
    void clear() {
        while (!empty())
            len--;
    }
    int size() {
        return len + 1;
    }
};
int main() {
    MyStack stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);

    cout << "size: " << stk.size() << endl;
    cout << "top ele: " << stk.top() << endl;
    cout << "popped " << stk.pop() << endl;
    cout << "popped " << stk.pop() << endl;
    cout << "is empty? : ";
    if(stk.empty()) cout << "true";
    else cout << "false";
    cout << endl;
    cout << "top ele " << stk.top() << endl;
    cout << "size: " << stk.size();

    return 0;
}