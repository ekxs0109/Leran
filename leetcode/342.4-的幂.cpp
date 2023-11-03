// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem342.h"
#include <algorithm>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        return n > 0 && (n & (n - 1)) == 0 && ((n & 0b10101010101010101010101010101010) == 0);
    }
};
// @lc code=end
