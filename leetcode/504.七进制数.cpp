// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <cmath>
#include "commoncppproblem504.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */

// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        if(num ==0) return "0";
        int absNum = abs(num);
        string res;
        while(absNum>0  ){
           res =  to_string(absNum %7) + res;
           absNum /=7;
        }
        if(num<0){
            res = '-' + res;
        }

        return res;

    }
};
// @lc code=end

