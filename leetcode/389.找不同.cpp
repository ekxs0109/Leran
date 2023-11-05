// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem389.h"

using namespace std;
// @before-stub-for-debug-end

// 创建频率表，然后循环t找到超出的字母
// 时间复杂度：O(nm)
// 空间复杂度：O(1) 空间与参数无关，故忽略为1

/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        int map[256] = {0};

        for(auto ch : s){
            map[ch]++;
        }

        for(auto ch:t){
            map[ch]--;
            if(map[ch] <0) {
                return static_cast<char>(ch);
            }
        }


        return ' ';
    }
};
// @lc code=end

