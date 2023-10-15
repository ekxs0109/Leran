// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem35.h"

using namespace std;
// @before-stub-for-debug-end

// [1,2,3,4,6] 2
//  p   m   q
// [1,2,3,4,6] 2
//  p q
//  m
// [1,2,3,4,6] 2
//    q
//    p
//    m

// [1,2,3,4,6] 7
//  p   m   q
// [1,2,3,4,6] 7
//        p q
//        m
// [1,2,3,4,6] 
//          q
//          p
//          m

// [1,2,3,4,6] 0
//  p   m   q
// [1,2,3,4,6] 
//  1
//  p
//  m

// 通过二分查找返回位置，如果未找到返回最左侧指针位置
// 时间复杂度：O(log n)
// 空间复杂度：O(1)
/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int p = 0, q = nums.size()-1,mid =0;
        while (q >= p)
        {
            mid = ((q - p) >> 1) + p;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                p = mid + 1;
            }
            else
            {
                q = mid - 1;
            }
        }
        return p;
    }
};
// @lc code=end
