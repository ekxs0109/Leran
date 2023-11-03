// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem191.h"

using namespace std;
// @before-stub-for-debug-end

// 内置函数__builtin_popcount， 或者位运算循环
// 时间复杂度：O(1) ，因为循环与参数无关
// 空间复杂度：O(1)

/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for(int i =0 ;i < 32;i++){
            if(n&1 == 1){
                res ++;
            }
            n>>=1;
        }
        return res;
    }
    int hammingWeightByStl(uint32_t n) {
        return __builtin_popcount(n);
    }
};
// @lc code=end

