// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem455.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int len = g.size(),sLen = s.size();
        int res = 0;

        int i =0,j=0;

        while(i <len && j<sLen){
            if(s[j] >= g[i]){
                i++;
                j++;
                res++;
            }else{
                j++;
            }
        }

        return res;

    }
};
// @lc code=end

