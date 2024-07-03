// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem645.h"

using namespace std;
// @before-stub-for-debug-end

// 1 2 2 3 4
// 1 2 3 4 5

/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] 错误的集合
 */

// @lc code=start
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int checkNum = 1;
        int replaceNum = -1;
        int res = -1;
        sort(nums.begin(),nums.end());

        for(int i =0 ; i<nums.size();i++){
            if( i<nums.size()-1 && nums[i] == nums[i+1]){
                replaceNum = nums[i];
                checkNum--;
            }else if(res ==-1&& checkNum!=nums[i]){
                res = checkNum;
            }

            checkNum++;
        }
        
        return {replaceNum,res==-1 ? nums[nums.size()-1]+1:res};
    }
};
// @lc code=end

