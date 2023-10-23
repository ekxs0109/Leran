// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <iostream>
#include <limits.h>
#include "commoncppproblem643.h"

using namespace std;
// @before-stub-for-debug-end
// [1,12,-5,-6,50,3] k=3
//           p       sum = 1+12...+-6
//           p       sum=sum - nums[p-k]+ nums[p];
// 

// 滑动窗口
// 时间复杂度：O(n)
// 空间复杂度：O(1)


/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start
class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int sum= 0 ,len = nums.size();
        for(int i =0;i<k;i++){
            sum += nums[i];
        }

        int maxSum = sum;
        for(int i= k;i<len;i++ ){
            sum = sum -nums[i-k] +nums[i];
            maxSum = max(sum,maxSum);
        }

        return  static_cast<double>(maxSum) / k;
    }
};
// @lc code=end
