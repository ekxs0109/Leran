// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem119.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

//          1          ----- 1
//         1 1         ----- 2
//        1 2 1        ----- 3
//       1 3 3 1       ----- 4
//      1 4 6 4 1      ----- 5
//     1 5 10 10 5 1    ---- 6
//   (6-1+1)/1 * 1 (6-2+1)/2 * 5 Math.floor( (6-3+1)/3 )*10
// 使用公式计算
// 时间复杂度： O(numRows)
// 空间复杂度： O(1)
// @lc code=start
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> res;
        res.push_back(1);   
        for(int i = 1;i<=rowIndex;i++){
            res.push_back(1LL *res[i-1] *(rowIndex-i+1) /i );// 必须先做乘法，最后做除法，不然会导致小数丢失
        }
        return res;
    }
};
// @lc code=end
