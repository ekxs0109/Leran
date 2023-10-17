// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "commoncppproblem169.h"


using namespace std;
// @before-stub-for-debug-end

// 先遍历一次计算重复测试，再遍历一次取最大值 
// TODO: 优化成O(n)算法
// 时间复杂度：O(2n)
// 空间复杂度: O(n)

/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=star=N
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        int len = nums.size();
        int maxLabel =0;
        int maxNum =0;
        for(int i =0; i<len; i++){
            map[nums[i]] = (map[nums[i]]? map[nums[i]]:0) + 1;
        }
        for(auto item:map){
            if(item.second> maxNum){
                maxNum =  item.second;
                maxLabel = item.first;
            }
        }
        return maxLabel;
    }
};
// @lc code=end

