// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem69.h"

using namespace std;
// @before-stub-for-debug-end

// x= 8
// x1=1 x2=4
// x1s=1 x2s = 16
// x1=2 x2=3
// x1s=4 x2s=9  选x1s


// 使用二分法暴力解
// 时间复杂度：O(log n)
// 空间复杂度: O(1)


/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */


// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
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
        return min(x1,x2);
    }
};
// @lc code=end

