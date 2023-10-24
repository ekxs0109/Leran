// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include <limits.h>
#include "commoncppproblem697.h"

using namespace std;
// @before-stub-for-debug-end

// 使用map记录每个元素的位置和最大出现次数，然后找到最大出现次数的元素中左右最接近的数组长度
// 时间复杂度: O(n)
// 空间复杂度：O(n)

/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */


// @lc code=start
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int>> map;
        
        int du = 0;

        for(int i=0; i<nums.size(); i++){
            if(map.count(nums[i])==0 ){
                map[nums[i]] = vector<int>();
            }
            map[nums[i]].push_back(i);
            du = max(du,static_cast<int>(map[nums[i]].size()));
        }

        int res = INT_MAX;
        for(auto it :map){
            if(it.second.size() == du ){
                res = min(*(it.second.rbegin())- *(it.second.begin()) +1,res);
            }
        }


        return res;

    }
};
// @lc code=end

