// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem367.h"

using namespace std;
// @before-stub-for-debug-end


// 使用二分法暴力解
// 时间复杂度：O(log n)
// 空间复杂度: O(1)


/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int x) {
        if(x==1) return 1;
        int x1=0, x2 = x>>1, mid =0;

        while (x1<=x2){
            mid = ((x2-x1) >> 1) + x1;

            double s = static_cast<double>(mid) * static_cast<double>(mid) ;

            if( s == static_cast<double>(x)){
                return mid;
            }else if (s < static_cast<double>(x)){
                x1 = mid +1;
            }else{
                x2 = mid -1;
            }
        }
        return false;
    }
};
// @lc code=end

