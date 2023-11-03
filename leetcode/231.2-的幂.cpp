// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem231.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2 的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && (n & (n-1)) == 0;
    }
};
// @lc code=end

