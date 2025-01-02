#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    void printList(Node* node) {
        while(node != NULL) {
            cout << node->value << " ";
            node = node->next;
        }
    }
};

int main() {
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();
    Node* fifth = new Node();

    head->value = 1;
    head->next = second;
    second->value = 2;
    second->next = third;
    third->value = 3;
    third->next = fourth;
    fourth->value = 4;
    fourth->next = fifth;
    fifth->value = 5;
    fifth->next = NULL;

    printList(head);
 
    return 0;
}