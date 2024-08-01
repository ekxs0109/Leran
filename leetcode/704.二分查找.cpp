// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem704.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid;
        while (left<=right)
        {
            mid = ((right-left)>>1)+left;
            if(nums[mid] == target) return mid;
            if(nums[mid] <target) {
                left = mid+1;
            }else{
                right = mid-1;
            }
        }

        return -1;
    }
};
// @lc code=end

