#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* arrToLL(vector<int> arr) { // converts array to a Linked-List
    if(arr.size() == 0) return NULL;
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

void printLL(Node* head) { // Prints Linked list
    Node* mover = head;
    while(mover) {
        cout << mover->data << " ";
        mover = mover->next;
    }
}

int findSizeOfLL(Node* head) { // returns the size of a linked list
    Node* mover = head;
    int size = 0;
    while(mover) {
        cout << mover->data << " ";
        mover = mover->next;
        size++;
    }
    return size;
}

bool checkIfPresent(Node* head, int target) { // checks if a given target element is present in the given LL or not
    Node* temp = head;
    while(temp) {
        if(temp->data == target) return true;
        temp = temp->next;
    }
    return false;
}

Node* deleteHead(Node* head) { // deletes the head of the LL
    if (head == NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* deleteTail(Node* head) { // deletes the tail of the LL
    if(head == NULL or head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next) {
        temp = temp->next;
    }
    // free(temp->next);
    temp->next = NULL;
    return head;
}

Node* deleteKthEle(Node* head, int k) { // Deleted the K-th element of the LL if its present there in the LL
    if(head == nullptr or k < 1) return head;
    if(findSizeOfLL(head) < k) return NULL;

    if(k == 1) return deleteHead(head);
    Node* temp = head;
    int i = 0;
    while(temp->next) {
        i++;
        if(i == k-1) {
            Node* toDlt = temp->next;
            temp->next = toDlt->next;
            delete toDlt;
            return head;
        }
        temp = temp->next;
    }
    return NULL;
}

int main() {
    vector<int> arr = {5,6,2,26,62,22};
    vector<int> arr2 = {1,2};

    Node* head = arrToLL(arr);
    // if(checkIfPresent(head, 62)) cout << "present";
    // else cout << "not present";
    // Node* newHead = deleteTail(head);
    // printLL(newHead);

    head = deleteKthEle(head, 6);
    printLL(head);

    return 0;
}