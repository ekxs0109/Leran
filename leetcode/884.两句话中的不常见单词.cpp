// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include "commoncppproblem884.h"

using namespace std;
// @before-stub-for-debug-end

// 时间复杂度：O(|s1| + |s2|)
// 空复杂度：O(|s1| + |s2|)

/*
 * @lc app=leetcode.cn id=884 lang=cpp
 *
 * [884] 两句话中的不常见单词
 */

// @lc code=start
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> dict;

        stringstream s1stream(s1);
        stringstream s2stream(s2);
        string item;

        while(getline(s1stream, item,' ')){
            dict[item] ++;
        }

        vector<string> res;

        while(getline(s2stream, item,' ')){
            dict[item] ++;
        }

        for(auto item : dict){
            if(item.second <2){
                res.push_back(item.first);
            };
        }
        return res;
    }
};
// @lc code=end

