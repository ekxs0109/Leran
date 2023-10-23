// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem605.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */
// [1,0,0,0,1] n=1
//  p       q  q-p-1 4-0-1
// [1,0,1,0,1,0,1] n=1
//  p       q  3 5 7

// 时间复杂度：O(n)
// 空间复杂度：O(1)

// @lc code=start
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int interval = 1, res = 0;

        for (auto item : flowerbed)
        {
            if (item == 0)
            {
                interval++;
            }
            else
            {
                res += (interval - 1) / 2;
                interval = 0;
            }
        }

        if (interval > 1)
        {
            res += interval / 2;
        }

        return res>=n;
    }
};
// @lc code=end
