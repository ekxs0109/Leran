// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem520.h"

using namespace std;
// @before-stub-for-debug-end

// 通过状态
// 时间复杂度：O(n)
// 空间复杂度：O(1)

/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 */

// @lc code=start
class Solution {
public:
    bool detectCapitalUse(string word) {
        int state = word[0]>='A' && word[0]<='Z' ?1 :0; 
        for(int i =1 ; i<word.size();i++){
            char ch = word[i];
            if(state ==2){
                if(ch >='A' && ch<='Z') continue;
                return false;
            }else if (state == 1){
                if(ch >='A' && ch<='Z'){
                    state = 2;
                }else{
                    state = 0;
                }
            }else{
                if(ch>='a'  && ch<='z') continue;
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

