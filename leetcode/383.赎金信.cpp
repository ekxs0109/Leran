// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem383.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size()> magazine.size()) return false;
        int cnt[26] = {0};

        for(auto ch:magazine){
            cnt[ch -'a'] ++;
        }

        for(auto ch:ransomNote){
            cnt[ch -'a'] --;
        }

        for(auto i:cnt){
            if(i<0) return false;
        }
        return true;


    }
};
// @lc code=end

