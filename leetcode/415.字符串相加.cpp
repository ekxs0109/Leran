// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <iostream>
#include "commoncppproblem415.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        int p = num1.size()-1,  q = num2.size()-1;

        string result;
        bool flag = false;
        char deci = '0' +10;
        while(p>-1 || q>-1){
            char ch = '0';
            if(p>-1){
                ch+= num1[p] - '0';
                p--;
            }
            if(q>-1){
                ch+= num2[q] - '0';
                q--;
            }
            if(flag){
                flag = false;
                ch++;
            }
            if(ch>=deci){
                ch -= 10;
                flag=true;
            }
            result = ch + result;
        }

        if(flag){
            result = '1' + result;
        }

        return result;

    }
};
// @lc code=end

