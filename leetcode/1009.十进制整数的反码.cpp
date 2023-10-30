// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <iostream>
#include <bitset>
#include "commoncppproblem1009.h"

using namespace std;
// @before-stub-for-debug-end

// 位运算
// 时间复杂度：O(1)
// 空间复杂度：O(1)

/*
 * @lc app=leetcode.cn id=1009 lang=cpp
 *
 * [1009] 十进制整数的反码
 */

// @lc code=start
class Solution
{
public:
    int bitwiseComplement(int n)
    {
        int highbit = 0;
        for (int i = 1; i <= 30; ++i)
        {
            if (n >= (1 << i))
            {
                highbit = i;
            }
            else
            {
                break;
            }
        }
        int mask = (highbit == 30 ? 0x7fffffff : (1 << (highbit + 1)) - 1); // 找到当前最高bit位，+1 向左移动，然后-1，使得 1000 变成0999
        // 如果最高位等于30，再+1 向左移动就占用了符号位，所以这里写死
        // cout<<"二进制"<<bitset<32>(mask)<<endl;
        return n ^ mask;
    }
};
// @lc code=end
