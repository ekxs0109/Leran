// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem628.h"
#include <algorithm>

using namespace std;
// @before-stub-for-debug-end

// [-100,-98,-1,2,3,4,99]

// 时间复杂度：O(n log n), n为数组长度; //排序
// 空间复杂度：O(1)


/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
 */

// @lc code=start
class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        int len = nums.size();
        sort(nums.begin(), nums.end());

        return max(nums[0] * nums[1] * nums[len - 1], 
        nums[len - 1] * nums[len - 2] * nums[len - 3]);
    }
};
// @lc code=end
