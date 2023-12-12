// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include "commoncppproblem20.h"

using namespace std;
// @before-stub-for-debug-end

// "([]({}))"

/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    bool dp(string s, int i,char lastCh,)
    {
        if(s[i] != lastCh) return false;

        return dp(s,i+1, s[i]);
    }
    bool isValid(string s)
    {
        unordered_map<char

        if (s.size() % 2 != 0)
            return false;
    }
};
// @lc code=end
