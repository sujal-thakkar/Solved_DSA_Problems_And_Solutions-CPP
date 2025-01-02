#include <bits/stdc++.h>
using namespace std;

class myVector {
    int* arr;
    int size, cap;
public:
    myVector() {
        arr = new int[1];
        size = 0;
        cap = 1;
    }
    void push_back(int num) {
        if (size < cap)
        {
            arr[size] = num;
            size++;
        } else 
        {
            int* new_arr = new int[2*cap];
            for(int i = 0; i < cap; i++)
                new_arr[i] = arr[i];
            delete []arr;
            arr = new_arr;
            cap *= 2;
            arr[size] = num;
            size++;
        }
    }
    void print() {
        for(int i = 0; i < size; i++)
            cout << arr[i] << ' ';
    }
};

int main() {
    myVector v;
    v.push_back(654);
    v.push_back(95);
    v.push_back(61);
    v.print();

    return 0;
}