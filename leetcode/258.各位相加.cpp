// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem258.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        int res = 0;

        while(num>0){
            res += num%10;
            num /=10;
        }

        return res>= 10?addDigits(res): res;
    }
};
// @lc code=end

