// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <iostream>
#include "commoncppproblem405.h"

using namespace std;
// @before-stub-for-debug-end

// 时间复杂度：O(k)，其中 k 是整数的十六进制数的位数，这道题中 k=8。无论 num\textit{num}num 的值是多少，都需要遍历 num 的十六进制表示的全部数位。

// 空间复杂度：O(k)，其中 k 是整数的十六进制数的位数，这道题中 k=8。空间复杂度主要取决于中间结果的存储空间，这道题中需要存储 num 的十六进制表示中的除了前导零以外的全部数位。


/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */



// @lc code=start
class Solution
{
public:
      string toHex(int num) {
        if (num == 0) {
            return "0";
        }
        string sb;
        for (int i = 7; i >= 0; i --) {
            int val = (num >> (4 * i)) & 0xf; // & 0xf 反码
            if (sb.length() > 0 || val > 0) {
                char digit = val < 10 ? (char) ('0' + val) : (char) ('a' + val - 10);
                sb.push_back(digit);
            }
        }
        return sb;
    }

    inline string padLeft(const string &str, int length, char paddingChar)
    {
        if (str.length() >= length)
        {
            return str;
        }

        string paddedStr(length - str.length(), paddingChar);
        paddedStr += str;
        return paddedStr;
    }
    string toHexBySelf(int num)
    {
        if(num ==0) return "0";
        bool negative = num < 0;
        num = abs(num + (negative ==false ? 0 : 1)) ;
        string res;

        while (num > 0)
        {
            int item = num % 16;

            if (item < 10)
            {
                res = to_string(item) + res;
            }
            else
            {
                res = string(1, item - 10 + 'a') + res;
            }
            num /= 16;
        }

        if (negative)
        {
            string nagativeRes = string("ffffffff");
            res = this->padLeft(res, 8, '0');
            for (int i = res.size() - 1; i > -1; i--)
            {
                if (res[i] > 'a')
                { 
                    nagativeRes[i] = 'f' - res[i] + '0';
                }
                else if (res[i] < '6')
                {
                    nagativeRes[i] = static_cast<char> ('f' -static_cast<int>(res[i] - '0'));

                }
                else
                {
                    int cur = (res[i]-'0') -5;
                    nagativeRes[i] = static_cast<char>(10 -cur + '0' );
                }
            }
            return nagativeRes;
        }

        return res;
    }
};
// @lc code=end
