// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "commoncppproblem434.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        stringstream st(s);
        string item;
        while(getline(st,item,' ')){
            if(!item.empty()) res++;
        }

        return res;
    }
};
// @lc code=end

