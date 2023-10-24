// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <limits.h>
#include "commoncppproblem747.h"

using namespace std;
// @before-stub-for-debug-end


// 找到第一大和第二大的数，注意第二大的数可能在最大数的后面
// 时间复杂度：O(n)
// 空间复杂度：O(1)

/*
 * @lc app=leetcode.cn id=747 lang=cpp
 *
 * [747] 至少是其他数字两倍的最大数
 */

// @lc code=start
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int bigestIndex =0, secondIndex = -1,len= nums.size();

        for(int i=1;i <len;i++){
            if(nums[i] > nums[bigestIndex]){
                secondIndex = bigestIndex;
                bigestIndex = i;
            }else if(secondIndex==-1 || nums[i]>nums[secondIndex] ){
                secondIndex = i;
            }
        }

        return (nums[bigestIndex] >= nums[secondIndex]<<1) ? bigestIndex:-1;
    }
};
// @lc code=end

