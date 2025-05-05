/* 146. LRU Cache (https://leetcode.com/problems/lru-cache/description/):

    Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

    Implement the LRUCache class:
    
    LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
    int get(int key) Return the value of the key if the key exists, otherwise return -1.
    void put(int key, int value) Update the value of the key if the key exists. 
    Otherwise, add the key-value pair to the cache. 
    If the number of keys exceeds the capacity from this operation, 
    evict the least recently used key.
    The functions get and put must each run in O(1) average time complexity. */

// t.c.= O(1) for put, O(1) for get s.c.= O(capacity);
#include <bits/stdc++.h>
using namespace std;

// Implementation of doubly-linked list:
class Node {
public:
    int key, val;
    Node* prev, *next;
    Node(int _key, int _val) : key(_key), val(_val), next(NULL), prev(NULL) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> m;
    Node* mru = new Node(-1, -1), *lru = new Node(-1, -1);

    void makeNodeMRU(Node* ptr) {
        if(mru->next == ptr) return;
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        ptr->next = mru->next;
        ptr->prev = mru;
        ptr->next->prev = ptr;
        mru->next = ptr;
    }
    void freeUpCache() {
        Node* toDlt = lru->prev;
        lru->prev = toDlt->prev;
        toDlt->prev->next = lru;
        m.erase(toDlt->key);
        delete toDlt;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        mru->next = lru;
        lru->prev = mru;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if(it == m.end()) return -1;
        Node* ptr = it->second;
        makeNodeMRU(ptr);
        return ptr->val;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if(it != m.end()) {
            m[key]->val = value;
            makeNodeMRU(m[key]);
            return;
        }
        if(m.size() >= capacity) {
            freeUpCache();
        }
        Node* newNode = new Node(key, value);
        m[key] = newNode;
        newNode->next = mru->next;
        newNode->prev = mru;
        newNode->next->prev = newNode;
        mru->next = newNode;
    }
};
    
/*
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
*/

int main() {
    LRUCache* obj = new LRUCache(3);
    obj->put(1,1);
    obj->put(2,2);
    int val = obj->get(1); cout << val << " ";
    obj->put(3,3);
    val = obj->get(2); cout << val << " ";
    obj->put(4,4);
    val = obj->get(1); cout << val << " ";
    val = obj->get(3); cout << val << " ";
    val = obj->get(4); cout << val << " ";
 
    return 0;
}