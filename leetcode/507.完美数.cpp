// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem507.h"

using namespace std;
// @before-stub-for-debug-end

// 时间复杂度：O(num)
// 空间复杂度：O(1)

/*
 * @lc app=leetcode.cn id=507 lang=cpp
 *
 * [507] 完美数
 */

// @lc code=start
class Solution {
public:
    bool checkPerfectNumber(int num) {
        int i = 1;
        int res = 0;
        while(i <num){
            if(num%i == 0){
                res+=i;

                if(res >num) return false;
            }
            i++;
        }
        return res == num;

    }
};
// @lc code=end

