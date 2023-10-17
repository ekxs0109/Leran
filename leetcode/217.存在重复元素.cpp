// @before-stub-for-debug-begin
#include <vector>
#include <unordered_set>
#include <string>
#include "commoncppproblem217.h"

using namespace std;
// @before-stub-for-debug-end


// 使用SET
// 时间复杂度：O(n)
// 空间复杂度：O(n)
/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for(auto num:nums){
            if(set.count(num)){
                return true;
            }
            set.insert(num);
        }
        return false;
    }
};
// @lc code=end

