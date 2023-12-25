// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "commoncppproblem557.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        stringstream strString(s);
        string item;
        string res;

        while(getline(strString, item,' ')){
            reverse(item.begin(),item.end());
            res += item +' ';
        }

        res.pop_back();

        return res;
    }
};
// @lc code=end

