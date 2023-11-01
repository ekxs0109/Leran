// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem441.h"

using namespace std;
// @before-stub-for-debug-end

// 二分法
//  时间复杂度：O(logn n)
//  空间复杂度：O(1)

/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        if(n==1) return n;
        int p =0,q =n ,mid = 0,result =0;

        while (p<=q){
            mid = ((q-p)>>1) + p;

            double sum = (1.0+mid) *  static_cast<double>(mid) / 2  ;
            if(sum == static_cast<double>(n)){
                return mid;
            }else if (sum <static_cast<double>(n)){
                result = mid;
                p = mid +1;
            }else{
                q = mid-1;
            }
        }
        return result;
    }
};
// @lc code=end

