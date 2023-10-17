// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <limits>
#include "commoncppproblem121.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// [7,1,5,3,6,4]
//    i
// [7,1,7,5,3,6,4]
//    i
//    n
// [7,1,7,5,3,6,4]
//      i
//    n m

// 找最小值，然后计算当前值-最小值是否是最大
// 时间复杂度：O(n)
// 空间复杂度：O(1)

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = numeric_limits<int>::max() ,max=0,len = prices.size();

        for(int i = 0;i < len;i++){
            if(prices[i] < min){
                min = prices[i];
            }else if(prices[i]-min > max){
                max = prices[i] -min;
            }
        }

        return max;
    }
};
// @lc code=end

