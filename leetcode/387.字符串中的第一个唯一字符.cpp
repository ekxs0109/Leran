// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem387.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        int cnt[26] = {0},len =s.size();

        for(int i = 0; i < len ; i++){
            cnt[s[i] - 'a'] ++;
        }

        for(int i = 0; i < len ; i++){
            if(cnt[s[i] - 'a'] == 1) return i;
        }

        return -1;
 
    }
};
// @lc code=end

