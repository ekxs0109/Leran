// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem674.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

//  单指针遍历
// 时间复杂度：O(n)
// 空间复杂度：O(1)

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int  q = 1, len = nums.size(), sum = 1,maxSum = 1;

        while(q< len){
            if(nums[q]>nums[q-1]){
                sum++;
            }else{
                maxSum = max(sum , maxSum);
                sum=1;
            }
            q++;
        }
        return max(sum , maxSum);
    }
};
// @lc code=end

