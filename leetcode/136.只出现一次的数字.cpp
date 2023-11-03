// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem136.h"

using namespace std;
// @before-stub-for-debug-end

// 时间复杂度：O(n)
// 空间复杂度：O(1)

/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;

        for(auto num: nums){
            res ^=num;
        }

        return res;
    }
};
// @lc code=end

