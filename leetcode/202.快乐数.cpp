// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <cmath>
#include "commoncppproblem202.h"

using namespace std;
// @before-stub-for-debug-end

// 快慢指针，等快慢指针相遇，判断结果是否为1
// 时间复杂度：O(log⁡n)
// 空间复杂度：O(1)

/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution
{
public:
    int bigSquareSum(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int bit = n % 10;
            sum += bit * bit;
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n)
    {
        int fast = n, slow = n;

        do
        {
            fast = bigSquareSum(fast);
            fast = bigSquareSum(fast);
            slow = bigSquareSum(slow);
        } while (fast != slow);

        return slow == 1;
    }
};
// @lc code=end
