// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem219.h"
#include <unordered_map>

using namespace std;
// @before-stub-for-debug-end


// 使用map
// 时间复杂度：O(n)
// 空间复杂度：O(n)

/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        
        for(int i =0;i< nums.size();i++){
            int num = nums[i];
            if(map.count(num)&& i-map[num] <=k){
                return true;
            }
            map[num] = i;
        }
        return false;
    }
};
// @lc code=end

