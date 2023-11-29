// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem28.h"

using namespace std;
// @before-stub-for-debug-end

// 滑动窗口

// 时间复杂度: O(n*m)，其中n是haystack的长度，m是needle的长度。因为在最坏情况下，需要遍历整个haystack，对于haystack中的每个位置，你可能需要遍历整个needle来检查是否有匹配。
// 空间复杂度：O(1)

/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        auto fatherLen = haystack.length();
        auto sonLen = needle.length();
        if (sonLen > fatherLen)
            return -1;

        int p = 0, q = 0, sonq = 0;

        while (q < fatherLen)
        {

            if (haystack[q] == needle[sonq])
            {
                if (sonq == 0)
                {
                    p = q;
                }
                q++;
                sonq++;
            }
            else
            {

                q = p + 1;
                sonq = 0;
                if (sonq == 0)
                {
                    p++;
                }
            }

            if ((q - p) == sonLen)
            {
                return p;
            }
        }
        return -1;
    }
};
// @lc code=end
