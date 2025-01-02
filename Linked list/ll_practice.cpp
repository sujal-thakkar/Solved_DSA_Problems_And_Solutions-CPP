#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};
int main() {
    Node* y = new Node(12, nullptr);
    cout << y->data << endl;
 
    return 0;
}