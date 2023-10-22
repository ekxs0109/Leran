// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem561.h"
#include <algorithm>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=561 lang=cpp
 *
 * [561] 数组拆分
 */

// 使用排序 然后每次遍历两个
// 时间复杂度：O(n log n) ,  排序O(n log n) ,遍历O(n/2),取最大数
// 空间复杂度：O(1)

// [6,2,6,5,1,2]
// [1,2,2,5,6,6] order
//  p             [p,p+1]

// @lc code=start
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int p =0, res=0, len =nums.size() -1;

        while(p < len){
            res += min(nums[p], nums[p+1]);
            p+=2;
        }
        return res;

    }
};
// @lc code=end

