// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include "commoncppproblem409.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> hash;
        auto res = 0;
        for(auto ch: s){
            hash[ch]++;
        }

        for(auto it :hash){
            if(it.second >1){
                res += (it.second >>1) <<1;
            }
        }
        if(res < s.size()){
            res++;
        }
        return  res;

    }
};
// @lc code=end

