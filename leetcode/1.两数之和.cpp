// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            if (map.find(nums[i]) != map.end())
            {
                return {map.find(nums[i])->second, i};
            }
            map[target-nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end
