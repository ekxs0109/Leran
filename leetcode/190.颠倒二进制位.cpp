// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem190.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBitsByFor(uint32_t n) {
        uint32_t reverseNum = 0;   
        for(int i =0;i<32;i++){
            reverseNum = (reverseNum<<1) | (n&1);
            n>>=1;
        }
        return reverseNum;
        
    }
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }

};
// @lc code=end

