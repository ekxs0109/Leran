// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem27.h"
#include <iostream>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// [0,1,2,2,3,0,4,2] 2
//  p             q
// [0,1,2,2,3,0,4,2]
//      p       q
// [0,1,4,2,3,0,2,2]
//        p   q
// 双指针 左右遍历，如果左指针需要删除，就将右边不为需要删除的元素移动到左。
// 时间复杂度： O(n)
// 空间复杂度： O(1)

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int p = 0, q = len-1;

        while(p<=q){ // 在相交时再走一次，让p向前走一步
            if(nums[q] == val){
                q--;
            }else if (nums[p] == val){
                nums[p] = nums[q];
                q--;
                p++;
            }else{
                p++;
            }
        }
        return p;
    }
};
// @lc code=end

