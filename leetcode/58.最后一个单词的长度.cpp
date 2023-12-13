// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem58.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        bool flag =false;;

        for(auto it = s.rbegin(); it!=s.rend();it++){
            if(*it != ' '){
                res++;
                flag= true;
            }else if (flag){
                break;
            }
        }
        return res;
    }
};
// @lc code=end

