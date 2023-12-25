// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem551.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] 学生出勤记录 I
 */

// @lc code=start
class Solution {
public:
    bool checkRecord(string s) {
        int ACount = 0;
        int BCount = 0;
        for(auto ch : s){
            if(ch == 'A'){
                ACount ++;
                BCount = 0;
            }else if(ch == 'L'){
                BCount ++;
            }else{
                BCount = 0;
            }

            if(ACount >=2 || BCount >=3){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

