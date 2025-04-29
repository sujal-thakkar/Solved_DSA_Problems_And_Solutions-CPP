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


Node* insertAtHead(Node* head, int ele) { // inserts a new node into the head of the LL, making it the new Head
    Node* newHead = new Node(ele, head);
    return newHead;
}

Node* deleteHead(Node* head) { // deletes the head of the LL
    if (head == NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* insertAtTail(Node* head, int ele) { // insert a new node at the end of the LL, making it the new tail
    if(head == NULL) return new Node(ele);
    Node* newNode = new Node(ele);
    Node* temp = head;
    while(temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
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

Node* insertAtKthIdx(Node* head, int k, int ele) { // insert an element at the K-th index of the LL
    if(k < 1) return head;
    if(k == 1) return new Node(ele);    
    Node* temp = head;
    int i = 1;
    while(temp and i != k-1) {
        temp = temp->next;
        i++;
    }
    if(!temp) return head;
    Node* newNode = new Node(ele, temp->next);
    temp->next = newNode;
    return head;
}

Node* insertBeforeEle(Node* head, int ele, int val) { // inserts a node before a given element in a LL
    if(head == NULL) return NULL ;
    if(head->data == ele) {
        return new Node(val, head);
    }
    Node* temp = head;
    while(temp->next and temp->next->data != ele){
        temp = temp->next;
    }
    if(!temp->next) return head;
    Node* newNode = new Node(val, temp->next);
    temp->next = newNode;
    return head;
}

Node* deleteKthEle(Node* head, int k) { // Deletes the K-th element of the LL if its present there in the LL
    if(head == nullptr or k < 1) return head;

    if(k == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

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
    cout << "provide valid k nigga!";
    return NULL;
}

Node* deleteTarget(Node* head, int target) { // deletes the given target element from the LL, if exist
    if(head == nullptr) return head;

    Node* temp = head;
    if(head->data == target) {
        head = head->next;
        delete temp;
        return head;
    }
    while(temp->next and temp->next->data != target) {
        temp = temp->next;
    }
    if(!temp->next) {
        cout << "target: " << target << " is not found in LL, 🖕\n";
        return head;
    }
    else {
        Node* toDlt = temp->next;
        temp->next = toDlt->next;
        delete toDlt;
        return head;
    }
}

int main() {
    vector<int> arr = {5,6,2,26,62,22};
    vector<int> arr2 = {};

    Node* head = arrToLL(arr);
    // if(checkIfPresent(head, 62)) cout << "present";
    // else cout << "not present";
    // head = deleteHead(head);
    // head = deleteTail(head);
    // head = deleteKthEle(head, 1);
    // head = deleteTarget(head, 1);
    // head = insertAtHead(head, 58);
    // head = insertAtTail(head, 87); 
    // head = insertAtKthIdx(head, 1, 99);
    head = insertBeforeEle(head, 25, 69);
    printLL(head);

    return 0;
}