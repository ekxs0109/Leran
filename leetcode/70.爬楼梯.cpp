// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include "commoncppproblem70.h"

using namespace std;
// @before-stub-for-debug-end

// dP + 缓存
// 时间复杂度：O(n)
// 空间复杂度：O(1)

/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
private:
    unordered_map<int,int> dp = {
            {1,1},
            {2,2}
        };
public:
    int climbStairs(int n) {
        if(dp[n]) return dp[n];
        dp[n] = climbStairs(n-1) + climbStairs(n-2);
        return dp[n];
    }
};
// @lc code=end

