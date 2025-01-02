#include <bits/stdc++.h>
using namespace std;

int arr[5];
int size = 0;
int i = 0;

void insertEle(int n) {
    if(size < 5) {
        arr[i] = n;
    i++;
    size++;
    } else {
        cout << "array is full can't insert " << n << endl;
    }
    
}
void printArr() {
    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
}

int main()
{
    insertEle(5);
    insertEle(45);
    insertEle(52);
    insertEle(57);
    insertEle(56);
    // extra element--
    insertEle(54);
    printArr();
    
    return 0;
}