// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem482.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=482 lang=cpp
 *
 * [482] 密钥格式化
 */

// @lc code=start
class Solution
{
public:
    string licenseKeyFormatting(string s, int k)
    {
        string res;
        int i = 0;
        for (auto it = s.rbegin(); it != s.rend(); it++)
        {
            if (*it == '-')
                continue;
            if (i > 0 && i % k == 0)
            {
                i = 0;
                res.push_back('-');
            }
            res.push_back(toupper(*it));
            i++;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
