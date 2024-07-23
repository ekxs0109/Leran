// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem682.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */

// @lc code=start




class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<string> stk;
        string left = "";
        string right = "";

        for(auto op: operations){
            switch (op[0])
            {
            case 'C':
                stk.pop();
                break;
            case 'D':
                left = stk.top();
                stk.push(to_string(stoi(left) * stoi(left)));
                break;
            case '+':
                
                stk.pop();
                right = stk.pop();
                stk.push(to_string(stoi(left) + stoi(right)));
                break;
            default:
                stk.push(op);
                break;
            }
        }

        int res = 0
        {
            res+=stoi(stk.top());
            stk.pop();
        }

        return res;
    }
};
// @lc code=end

