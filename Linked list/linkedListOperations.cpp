#include <bits/stdc++.h>
using namespace std;

// class to create a node of linked list
class Node {
public:
    int data;
    Node *next;

    Node(int data1, Node *next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};
// function to convert an array to linked list
Node *convertArr2LL(vector<int> &arr) {
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++) {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp; // or, mover = mover->next;
    }
    return head;
}
// funtion to print the length of a linked list
int printLengthOfLL(Node *head) {
    int cnt = 0;
    Node *temp = head;
    while (temp) {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}
// function to check if an element is present in the linked list or not
bool isElePresentInLL(Node *head, int element) {
    Node *temp = head;
    while (temp) {
        if (temp->data == element)
            return true;
        temp = temp->next;
    }
    return false;
}
int main() {
    vector<int> arr = {61, 5, 9, 4, 10};
    Node *head = convertArr2LL(arr);
    Node *temp = head;
     
    // traverse through the linked list->
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    cout << "length of LL: " << printLengthOfLL(head);
    cout << endl;
    int element = 20;
    bool ans = isElePresentInLL(head, element);
    if (ans)
        cout << "yes, " << element << " is present!";
    else
        cout << element << " is Not present";
    return 0;
}