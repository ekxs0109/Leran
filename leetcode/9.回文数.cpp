// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <cmath>
#include "commoncppproblem9.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;

        double source = x;
        double res = 0;
        int bit = 0;

        while (x>0){
            res = res*10 + x%10;
            x /=10;
            bit++;
        }

        return res ==source;
    }
};
// @lc code=end

