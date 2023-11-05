// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <iostream>
#include "commoncppproblem405.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */

// @lc code=start
class Solution
{
public:
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
    string toHex(int num)
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
