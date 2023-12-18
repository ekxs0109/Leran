// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <cmath>
#include "commoncppproblem492.h"

using namespace std;
// @before-stub-for-debug-end

// 先算平方根，再判断
// 时间复杂度：O(sqrt(area))
// 空间复杂度：O(1)
/*
 * @lc app=leetcode.cn id=492 lang=cpp
 *
 * [492] 构造矩形
 */

// @lc code=start
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int W = sqrt(area);

        while(area % W !=0){
            W--;
        }
        return {area /W, W};

    }
};
// @lc code=end

