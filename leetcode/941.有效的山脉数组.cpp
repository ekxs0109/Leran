[1,3,2]
// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <limits.h>
#include "commoncppproblem941.h"

using namespace std;
// @before-stub-for-debug-end

// 使用状态管理解的，可能双指针还要快点...
// 时间复杂度：O(n)
// 空间复杂度：O(1)

/*
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] 有效的山脉数组
 */

// @lc code=start
class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        int peakNum = INT_MIN, len = arr.size();
        int isClimb = -1; // -1 no , 1 readly, >1 ing, 0 down

        for (auto num : arr)
        {
            switch (isClimb)
            {
            case -1:
                peakNum = num;
                isClimb = 1;
                break;

            case 0:
                if (num < peakNum)
                {
                    peakNum = num;
                }
                else
                {
                    return false;
                }
                break;
            default:
                if (num < peakNum)
                {
                    if (isClimb == 1)
                        return false;
                    peakNum=num;
                    isClimb = 0;
                }
                else if (num == peakNum)
                {
                    return false;
                }
                else
                {
                    peakNum = num;
                    isClimb++;
                }
                break;
            }
        }

        return isClimb == 0;
    }
};
// @lc code=end
