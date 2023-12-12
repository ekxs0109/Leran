// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem14.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];
        int shorest = res.size();
        for(int i=1;i<strs.size();i++){
            auto item = strs[i];
            while(res != item.substr(0,shorest)){
                shorest--;
                res = res.substr(0,shorest);
            }
        }

        return res;
    }
};
// @lc code=end

