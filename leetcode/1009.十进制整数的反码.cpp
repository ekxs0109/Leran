// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <iostream>
#include <bitset>
#include "commoncppproblem1009.h"

using namespace std;
// @before-stub-for-debug-end

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
        int mask = (highbit == 30 ? 0x7fffffff : (1 << (highbit + 1)) - 1);
        // cout<<"二进制"<<bitset<32>(mask)<<endl;
        return n ^ mask;
    }
};
// @lc code=end
