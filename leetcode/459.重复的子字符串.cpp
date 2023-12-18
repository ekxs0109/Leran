// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem459.h"

using namespace std;
// @before-stub-for-debug-end

// TODO: 使用KMP算法

/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();

        for(int i = 1;i *2 <=len ;++i){
            if(len%i ==0){
                bool match =true;
                for(int j = i ;j <len;j++){
                    if(s[j] != s[j-i]){
                        match = false;
                        break;
                    }
                }
                if(match){
                    return true;
                }
            }
        }

        return false;
    }
};
// @lc code=end

