// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem283.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
// [0,1,0,3,12]
//  p q
// [1,0,0,3,12]
//    p   q    
// [1,3,0,0,12]
//    p   q    
// [1,3,0,0,12]
//    p      q    
// [1,3,12,0,0]
//    p      q    
// 快慢指针
// 时间复杂度：O(n)
// 空间复杂度：O(1)

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p =0,q=1,len=nums.size();

        while(q<len&&p<len){
            if(nums[p]==0){
                if(nums[q] !=0){
                    swap(nums[p++],nums[q++]);
                }else{
                    q++;
                }
            }else{
                p++;
                q++;
            }
        }
    }
};
// @lc code=end

