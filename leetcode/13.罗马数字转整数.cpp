// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include "commoncppproblem13.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution
{
public:
    int romanToInt(string s)
    {
        auto hash = unordered_map<char, int>();
        hash['I'] = 1;
        hash['V'] = 5;
        hash['X'] = 10;
        hash['L'] = 50;
        hash['C'] = 100;
        hash['D'] = 500;
        hash['M'] = 1000;
        int res = 0;

        for (int i = 0; i < s.size(); i++)
        {
            int value = hash[s[i]];
            if(i < s.size() -1 && value < hash[s[i+1]]){
                res-=value;
            }else{
                res+=value;
            }
        }
        return res;
    }
};
// @lc code=end
