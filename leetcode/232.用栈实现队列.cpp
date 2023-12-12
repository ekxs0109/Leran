// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem232.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
private:
    stack<int> st1;
    stack<int> st2;
public:
    MyQueue() {

    }
    
    void push(int x) {
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }

        st2.push(x);
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        // swap(st2,st1);
    }
    
    int pop() {
        auto res = st1.top();
        st1.pop();
        return res;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
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
// @lc code=end

