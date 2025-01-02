/* 707. Design Linked List(https://leetcode.com/problems/design-linked-list/description/):

Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next.
val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute
- 'prev' to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed. */

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *prev;
    Node *next;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
class MyLinkedList {
public:
    Node *head;
    int length;

    MyLinkedList() {
        head = NULL;
        length = 0;
    }

    int get(int index) {
        if(length == 0 or index >= length) return -1; 
        Node* temp = head;
        for(int i=0; i<index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    void addAtHead(int val) {
        Node *newHead = new Node(val);
        newHead->next = head;
        if (head != NULL) {
            head->prev = newHead;
        }
        head = newHead;
        length++;
    }

    void addAtTail(int val) {
        if (head == NULL) {
            addAtHead(val);
            length++;
        }
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        Node *newTail = new Node(val);
        newTail->prev = temp;
        newTail->next = temp->next;
        temp->next = newTail;
        length++;
    }

    void addAtIndex(int index, int val) {
        if (index > length)
            return;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        if (index == length) {
            addAtTail(val);
            return;
        }

        Node *temp = head;
        for (int i = 0; i < index; i++) {
            if (i == index - 1) {
                Node *newNode = new Node(val);
                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next = newNode;
                length++;
                return;
            }
            temp = temp->next;
        }
    }

    void deleteAtIndex(int index) {
        if (index >= length or length == 0)
            return;

        if (index == 0) {
            Node *toDlt = head;
            if (length == 1) {
                head = NULL;
                delete todlt;
                length--;
                return;
            }
            head->next->prev = NULL;
            head = head->next;
            delete toDlt;
            length--;
            return;
        }
        Node *temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        if(temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        delete temp;
        length--;
    }
};

/* *
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index); */

int main() {
    MyLinkedList *obj = new MyLinkedList();
    int param_1 = obj->get(index);
    obj->addAtHead(val);
    obj->addAtTail(val);
    obj->addAtIndex(index, val);
    obj->deleteAtIndex(index);

    return 0;
}