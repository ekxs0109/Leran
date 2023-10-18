// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>
#include "commoncppproblem414.h"

using namespace std;
// @before-stub-for-debug-end

// 使用小顶堆
// 时间复杂度：O(n log k) k=3
// 空间复杂度：O(n)

// 使用排序set
// 时间复杂度：O(n)
// 空间复杂度：O(1)
/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */

// @lc code=start
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        set<int> set; // 排序set
        for (auto num : nums)
        {
            set.insert(num);
            if (set.size() > 3)
            {
                set.erase(set.begin());
            }
        }
        return (set.size() < 3) ? *set.rbegin() : *set.begin();
    }
    int thirdMaxBySmallHeap(vector<int> &nums)
    {
        priority_queue<int, vector<int>, greater<int>> sh; // 小顶堆
        unordered_set<int> set(nums.begin(), nums.end());
        for (auto num : set)
        {
            sh.push(num);
            if (sh.size() > 3)
            {
                sh.pop();
            }
        }
        while (sh.size() < 3 && sh.size() > 1)
        {
            sh.pop();
        }
        return sh.top();
    }
};
// @lc code=end
