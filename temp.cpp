#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};
int main() {
    Node* head = new Node(5);
    Node* newnode = new Node(6);
    head->next = newnode;

    cout << typeid(head).name() << endl;
    cout << head->next << endl;
    cout << head << endl;
    cout << newnode;

 
    return 0;
}