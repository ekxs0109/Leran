// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem228.h"

using namespace std;
// @before-stub-for-debug-end


// 时间复杂度：O(n)
// 空间复杂度：O(1)
/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int last = 0;

        for(int i =0; i<nums.size();i++){
             if(i== nums.size()-1|| nums[i]+1 != nums[i+1]){
                res.push_back((last ==i ?"":to_string(nums[last])+"->")+to_string(nums[i]));
                last= i+1;
            }
        }
        return res;

    }
};
// @lc code=end

