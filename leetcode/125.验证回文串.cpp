// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem125.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        string res ;
        for(auto it =s.rbegin();it!=s.rend(); it++ ){
            if((*it>= 'A' && *it <='Z') || (*it >='a' && *it <='z') ){
                res+= tolower(*it);
            }else if(*it>='0' && *it <= '9'){
                res+= *it;
            }
        }

        string rRes = res;
        reverse(rRes.begin(),rRes.end());
        return res == rRes;
    }
};
// @lc code=end

