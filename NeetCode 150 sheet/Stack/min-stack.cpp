/* 155. Min Stack (https://leetcode.com/problems/min-stack/description/):

    Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function. */

#include <bits/stdc++.h>
using namespace std;

class MinStack {
    private:
    stack<pair<int,int>> st;

    public:
        MinStack() {}
        
        void push(int val) {
            int minEle;
            if(st.empty()) minEle = val;
            else minEle = min(st.top().second, val);
            st.push({val, minEle});
        }
        
        void pop() {
            st.pop();
        }
        
        int top() {
            return st.top().first;
        }
        
        int getMin() {
            return st.top().second;
        }
    };
    
    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(val);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->getMin();
     */
int main() {
    MinStack obj = new MinStack();
    obj.push(23);
    obj.push(12);
    obj.push(5);
    int minEle = obj.getMin();
    obj.pop();
    int topEle = obj.top();
    obj.push(1);
 
    return 0;
}