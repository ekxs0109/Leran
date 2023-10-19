/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续 1 的个数
 */

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cur = 0;
        int max = 0;
        for(auto num:nums){
            if(num ==1){
                cur++;
            }else{
                cur=0;
            }
            if(cur >max){
                max = cur;
            }
        }
        return max;

    }
};
// @lc code=end

