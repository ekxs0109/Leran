// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem495.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */

// [1,2,3,4,5] 5
//p n
// [1,2,3,4,5] 5
//  p n        p+d-1=5 res=5
// [1,2,3,4,5] 5
//    p n        p+d-1=6 res=5 + 2-1
// [1,2,3,4,5] 5
//    p n        p+d-1=5 res=5 + 1
// 记录上一次的值，如果比next值比当前值大 对比当前值-上一次的值-1 获得差值加到结果上，否继续+持续值
// 时间复杂度：O(n)
// 空间复杂度：O(1)


// @lc code=start
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res =0,prev =-1;

        for(auto num: timeSeries){
            if(prev >-1 && num <= (prev+duration-1) ){
                res += num - prev;
                prev = num;
                continue;
            }
            res+=duration;
            prev = num;
        }

        return res;
    }
};
// @lc code=end

