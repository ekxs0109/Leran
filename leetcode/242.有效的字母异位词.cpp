// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include "commoncppproblem242.h"

using namespace std;
// @before-stub-for-debug-end

// 时间复杂度 O(n)
// 空间复杂度：O(n)

/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> hash;

        if(t.size()> s.size()){
            swap(t,s);
        }

        for(auto ch:s){
            hash[ch]++;
        }
        for(auto ch:t){
            hash[ch]--;
        }

        for(auto it : hash){
            if(it.second >0) return false;
        }
        return true;
    }
};
// @lc code=end

