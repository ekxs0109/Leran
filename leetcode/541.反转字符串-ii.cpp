// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem541.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int len = s.size();
        stack<char> que;
        string res;
        bool flag = true;

        for (int i = 0; i < len; i++)
        {
            if (flag)
            {

                if (i == 0 || i % k != 0)
                {
                    que.push(s[i]);
                }
                else
                {
                    while (!que.empty())
                    {
                        res += que.top();
                        que.pop();
                    }
                    res += s[i];

                    flag = false;
                }
            }
            else
            {
                if (i % k == 0)
                {
                    que.push(s[i]);
                    flag = true;
                }else{
                    res += s[i];

                }
            }
        }
        while (!que.empty())
        {
            res += que.top();
            que.pop();
        }

        return res;
    }
};
// @lc code=end
