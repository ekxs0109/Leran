// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include "commoncppproblem290.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream strString(s);
        string item;
        unordered_map<string,char> dict;
        unordered_set<char> used;
        auto i =0;
        while(getline(strString, item,' ')){
           if(!dict[item] ) {
            if(used.count(pattern[i]))return false;
            dict[item] = pattern[i];
            used.emplace(pattern[i]);
           }else if (dict[item] !=pattern[i]){
            return false;
           }
           i++;
        }

        return i == pattern.size();

    }
};
// @lc code=end

