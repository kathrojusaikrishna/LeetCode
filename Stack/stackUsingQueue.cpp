// Problem: Implement stack using queue
// Difficulty: Easy
// Platform: Leetcode
// Approach: using 2 stacks
// Time: O(n)
// Space: O(n)

class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;
    MyQueue() {
    }
    
    void push(int x) {
        while(!s1.empty()){
            int node = s1.top();
            s1.pop();
            s2.push(node);
        }
        s1.push(x);

        while(!s2.empty()){
            int node = s2.top();
            s2.pop();

            s1.push(node);
        }
    }
    
    int pop() {
        int node = s1.top();
        s1.pop();

        return node;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */