#include <bits/stdc++.h>
using namespace std;

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
        next = NULL;
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
// function to insert a new element at the head of the LL ->
Node *insertEleAtHead(Node *head, int element) {
    return new Node(element, head);
}
// function to insert a new element at the tail(last) of the LL ->
Node *insertEleAtTail(Node *head, int ele) {
    if (head == NULL) {
        return new Node(ele, NULL);
    }
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    Node *newNode = new Node(ele, NULL);
    temp->next = newNode;

    return head;
}
// function to insert an element at a given index K ->
Node *insertEleAtK(Node *head, int ele, int k) {
    if (head == NULL) {
        if (k == 1) {
            return new Node(ele);
        } else
            return NULL;
    } else if (k == 1) {
        return new Node(ele, head);
    } else {
        Node *temp = head;
        int cnt = 0;
        while (temp->next != NULL) {
            cnt++;
            if (cnt == k - 1) {
                Node *newNode = new Node(ele, temp->next);
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }
    }
    return head;
}
// function to insert an element before a given element(not index!) ->
Node *insertBeforeGivenEle(Node *head, int ele, int target) {
    Node *temp = head;
    if (temp->data == target) {
        Node *newHead = new Node(ele, head);
        return newHead;
    }
    while (temp->next != NULL) {
        if (temp->next->data == target) {
            Node *newNode = new Node(ele, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}
// function to delete the head node of the linked list ->
Node *dltHead(Node *head) {
    if (head == NULL)
        return NULL;
    Node *temp = head;
    head = head->next;
    delete temp; // or, free(temp);
    return head;
}
// function to delete the tail node of the linked list ->
Node *dltTail(Node *head) {
    if (head == NULL or head->next == NULL)
        return NULL;
    Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}
// function to delete an element from the K-th position of the linked list ->
Node *dltAtK(Node *head, int k) {
    if (head == NULL)
        return head;
    if (k == 1) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL) {
        cnt++;
        if (cnt == k - 1) {
            Node *oldNode = temp->next;
            temp->next = temp->next->next;
            delete oldNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}
// funtion to delete the given element from the linked list(if present) ->
Node *dltEle(Node *head, int ele) {
    if (head == NULL)
        return head;
    if (head->data == ele) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *temp = head;
    while (temp->next != NULL) {
        if (temp->next->data == ele) {
            Node *oldNode = temp->next;
            temp->next = temp->next->next;
            delete oldNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}
int main() {
    vector<int> arr = {61, 5, 9, 4, 10};
    Node *head = convertArr2LL(arr);

    Node *temp = dltEle(head, 4);

    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}