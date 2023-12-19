// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem521.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=521 lang=cpp
 *
 * [521] 最长特殊序列 Ⅰ
 */

// @lc code=start
class Solution {
public:
    int findLUSlength(string a, string b) {
        return a !=b? max(a.size(),b.size()) :-1;
    }
};
// @lc code=end

