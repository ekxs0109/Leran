// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <queue>
#include "commoncppproblem225.h"

using namespace std;
// @before-stub-for-debug-end

// [1,2,3]
// [1]

/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
public:
    queue<int> que1; // 保存反向stack
    queue<int> que2;
    MyStack() {
    }
    
    void push(int x) {
        que2.push(x);
        while (!que1.empty())
        {
            que2.push(que1.front());
            que1.pop();
        }
        swap(que2,que1);
    }
    
    int pop() {
        auto res = que1.front();
        que1.pop();
        return res;
    }

    int top() {
        return que1.front();
    }
    
    bool empty() {
        return que1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

