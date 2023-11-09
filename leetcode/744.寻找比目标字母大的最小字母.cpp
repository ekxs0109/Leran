// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem744.h"

using namespace std;
// @before-stub-for-debug-end

// 时间复杂度：O(n)
// 空间复杂度：O(1)

/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int res = 25;
        for(auto ch : letters){
            if(ch-target >0){
                res= min(res, ch-target);
            }
        }
        
        if(target+res > 'z'){
            return letters[0];
        }else{
            return target+res;
        }
    }
};
// @lc code=end

