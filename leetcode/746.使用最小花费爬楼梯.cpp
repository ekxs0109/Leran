// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem746.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        function<int(int, int)> func;
        func = [&](int res = 0,int i=0)->int{
            if(cost.size()-i <=1)  {
                return min(res, res+cost[i+1]);
            };
            int oneRes = res+cost[i];
            int twoRes = res+cost[i+1];
            return func(oneRes<twoRes ? oneRes :twoRes,oneRes<twoRes?i+1:i+2);
        };

        return min(func(0 ,0),func(0,1));
    }
};
// @lc code=end

