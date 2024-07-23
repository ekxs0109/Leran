// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem657.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */

// @lc code=start
class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;


        for(auto ch:moves){
            switch (ch)
            {
            case 'U':
                y++;
                break;
            case 'D':
                y--;
                break;
            case 'L':
                x--;
                break;
            case 'R':
                x++;
                break;
            default:
                break;
            }
        }

        return x==0 && y==0;
    }
};
// @lc code=end

