// @before-stub-for-debug-begin
#include <vector>
#include <cmath>
#include <string>
#include "commoncppproblem171.h"

using namespace std;
// @before-stub-for-debug-end

// 进制转换
// 时间复杂度：O(n)
// 空间复杂度：O(1)

/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int len = columnTitle.size();
        int res = 0;
        
        for(int i=0; i<len; i++){
            res += max((int)pow(26 , (len-i -1 ) ) ,1)  * ( (int)(columnTitle[i] -'A') + 1) ;
        }

        return res;

    }
};
// @lc code=end

