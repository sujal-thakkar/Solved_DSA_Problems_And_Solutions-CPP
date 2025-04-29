#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1, Node* prev1, Node* next1) {
        data = data1;
        prev = prev1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        prev = nullptr;
        next = nullptr;
    }
};

Node* convertArr2DLL(vector<int>& arr) { // converts an array to Doubly Linked-List
    if(arr.size()==0) return NULL;
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i=1; i<arr.size(); i++) {
        Node* newNode = new Node(arr[i], temp, nullptr);
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}

void print(Node* head) { // prints DLL
    if(head == NULL) cout << "NULL";
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* deleteHead(Node* head) { // deletes head node
    if(!head) return head;
    Node* temp = head;
    head = head->next;
    if(head) head->prev = nullptr; // this line is important because if we deleted the previous node but the head's prev still points to it's location then it will still hold the memory, and will give undefined behavior.
    // temp->next = nullptr; // very crumbersome. DO I NEED TO DO THIS!
    delete temp;
    return head;
}

Node* insertAtHead(Node* head, int n) { // inserts new ele at the head node
    if(!head) return new Node(n);
    Node* newHead = new Node(n, nullptr, head);
    head->prev = newHead;
    return newHead;
} 

Node* deleteTail(Node* head) { // deletes tail node
    /* if(!head) return head;
    Node* temp = head;
    while(temp->next) temp = temp->next;
    if(!temp->prev) head = NULL;
    else {
        temp->prev->next = nullptr;
        temp->prev = nullptr;
    }
    delete temp;
    return head; */
    if(!head or !head->next) return NULL;
    Node* temp = head;
    while(temp->next) temp = temp->next;
    temp->prev->next = nullptr;
    temp->prev = nullptr;
    delete temp;
    return head;
}

Node* insertBeforeTail(Node* head, int n) { // inserts a node before the tail node
    if(!head or !head->next) return insertAtHead(head, n);
    Node* temp = head;
    while(temp->next) temp = temp->next;
    Node* newNode = new Node(n, temp->prev, temp);
    temp->prev = newNode;
    newNode->prev->next = newNode;
    return head;
}

Node* insertAtTail(Node* head, int n) { // inserts a node at the tail
    if(!head) return new Node(n);
    Node* temp = head;
    while(temp->next) {
        temp = temp->next;
    }
    Node* newTail = new Node(n, temp, nullptr);
    temp->next = newTail;
    return head;
}

Node* deleteKthNode(Node* head, int k) { // deletes the node present at k-th index
    if(!head or k < 1) return head;
    Node* temp = head;
    if(k == 1) {
        head = head->next;
        head->prev = nullptr;
        delete temp;
        return head;
    }
    int i = 1;
    while(temp and i < k) {
        temp = temp->next;
        i++;
    }
    if(!temp) return head;
    temp->prev->next = temp->next;
    delete temp;
    return head;

    /* if(!head) return head;
    int cnt = 0;
    Node* kNode = head;
    while(kNode) {
        cnt++;
        if(cnt == k) break;
        kNode = kNode->next;
    }
    Node* previous = kNode->prev;
    Node* front = kNode->next;
    if(!previous and !front) return NULL;
    else if(!previous) return deleteHead(head);
    else if(!front) return deleteTail(head);
    previous->next = front;
    front->prev = previous;
    kNode->next = nullptr;
    kNode->prev = nullptr;
    delete kNode;

    return head; */
}

Node* insertAtKthIdx(Node* head, int k, int n) { // inserts a node at given valid index
    if(k < 1) return head;
    if(!head and k > 1) return head;
    if(k == 1) {
        Node* newNode = new Node(n, nullptr, head);
        if(head) head->prev = newNode;
        return newNode;
    }
    Node* temp = head;
    int i = 1;
    while(i < k) {
        if(!temp) return head;
        temp = temp->next;
        i++;
    }
    Node* newNode = new Node(n, temp->prev, temp);
    newNode->prev->next = newNode;
    temp->prev = newNode;
    return head;
}

Node* insertBeforeNode(Node* head, Node* nude, int n) { // inserts node before a given node
    if(!head) return head;
    Node* temp = head;
    while(temp->next and temp != nude) {
        temp = temp->next;
    }
    if(temp == nude) {
        Node* newNode = new Node(n, temp->prev, temp);
        temp->prev = newNode;
        newNode->prev->next = newNode;
    }
    return head;
}

Node* deleteTarget(Node* head, int target) { // deletes the given target from the DLL
    if(!head) return head;
    Node* temp = head;
    if(head->data == target) {
        head = head->next;
        delete temp;
        return head;
    }
    while(temp and temp->data != target) temp = temp->next;
    if(!temp) return head;
    temp->prev->next = temp->next;
    delete temp;
    return head;
}   

int main() {
    vector<int> arr = {5,9,2,0,4,10};
    vector<int> arr2 = {};
    Node* head = convertArr2DLL(arr);
    // head = deleteHead(head);
    // head = deleteTail(head);
    // head = deleteKthNode(head, 1);
    // head = deleteTarget(head, 10);
    // head = insertAtHead(head, 56);
    // head = insertAtTail(head, 61);
    // head = insertAtKthIdx(head, 6, 32);
    // head = insertBeforeTail(head, 99);
    head = insertBeforeNode(head, head->next->next->next->next, 163);
    print(head);
 
    return 0;
}