// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include "commoncppproblem268.h"

using namespace std;
// @before-stub-for-debug-end

// 使用set
// 时间复杂度：O(n)
// 空间复杂度：O(n)
/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        unordered_set<int> set(nums.begin(),nums.end());
        for(int i=0;i<len;i++){
            if(!set.count(i))return i;
        }
        return len;
    }
};
// @lc code=end

