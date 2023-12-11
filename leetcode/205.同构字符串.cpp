// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "commoncppproblem205.h"

using namespace std;
// @before-stub-for-debug-end

// 一个hashmap+一个hashSet
// 时间复杂度：O(n)
// 空间复杂度：O(|Σ|)


/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.size();
        unordered_map<char,char> dict;
        unordered_set<char> set;
        for(int i =0;i <len; i++){
            if(!dict[s[i]] ){
                if(set.count(t[i]) >0){
                    return false;
                }
                dict[s[i]] = t[i];
                set.insert(t[i]);
                continue;
            }
            if(dict[s[i]] != t[i]){
                return false;
            }

        }
        return true;
    }
};
// @lc code=end

