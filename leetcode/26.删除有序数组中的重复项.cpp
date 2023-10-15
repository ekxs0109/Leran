// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem26.h"

using namespace std;
// @before-stub-for-debug-end

// [0,0,1,1,1,2,2,3,3,4]
//  p q
// [0,1,1,1,1,2,2,3,3,4]
//    p q
// [0,1,2,1,1,2,2,3,3,4]
//      p         q
// 因为是顺序数组，将当前p跟快指针q对比，如果不一致，将q的值移动到p的下一个位置。
// 时间复杂度：O(n)
// 空间复杂度：O(1)

/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int len = nums.size();
        int p = 0;
        int q = p + 1;

        while (q < len)
        {
            if (nums[p] != nums[q])
            {
                nums[p + 1] = nums[q];
                q++;
                p++;
            }
            else
            {
                q++;
            }
        }
        return p+1;
    }
};
// @lc code=end
