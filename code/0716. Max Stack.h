/*
Design a max stack that supports push, pop, top, peekMax and popMax.

push(x) -- Push element x onto stack.
pop() -- Remove the element on top of the stack and return it.
top() -- Get the element on the top.
peekMax() -- Retrieve the maximum element in the stack.
popMax() -- Retrieve the maximum element in the stack, and remove it. 
            If you find more than one maximum elements, only remove the top-most one.
*/

class MaxStack {
private:
    list<int> l;
    map<int, vector<list<int>::iterator>> m;
public:
    /** initialize your data structure here. */
    MaxStack() {
    }
    
    void push(int x) {
        l.push_back(x);
        m[x].push_back(--l.end());
        return;
    }
    
    int pop() {
        int val=l.back();
        m[val].pop_back();
        if(!m[val].size()) m.erase(val);
        l.pop_back();
        return val;
    }
    
    int top() {
        return l.back();
    }
    
    int peekMax() {
        auto ii=--m.end();
        return ii->first;
    }
    
    int popMax() {
        int val=m.rbegin()->first;
        l.erase(m[val].back());
        m[val].pop_back();
        if(!m[val].size()) m.erase(val);
        return val;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
