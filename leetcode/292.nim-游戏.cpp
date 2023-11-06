// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem292.h"

using namespace std;
// @before-stub-for-debug-end
// 等于4无法获胜，4的倍数

/*
 * @lc app=leetcode.cn id=292 lang=cpp
 *
 * [292] Nim 游戏
 */

// @lc code=start
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 !=0;
    }
};
// @lc code=end

