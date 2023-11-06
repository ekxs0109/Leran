// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem693.h"

using namespace std;
// @before-stub-for-debug-end

// 时间复杂度：O(k) k 为 num二进制的位数
// 空间复杂度：O(1)

/*
 * @lc app=leetcode.cn id=693 lang=cpp
 *
 * [693] 交替位二进制数
 */

// @lc code=start
class Solution
{
public:
    bool hasAlternatingBits(int num)
    {
        int last = -1;
        while (num > 0)
        {
            int item = num % 2;

            if(last == -1 || last !=item){
                last = item;
            }else{
                return false;
            }
            num /= 2;
        }
        return true;
    }
};
// @lc code=end
