// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_set>
#include "commoncppproblem500.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 */

// @lc code=start
class Solution
{
public:
    vector<string> findWords(vector<string> &words)
    {
        string lineOne = "qwertyuiop";
        unordered_set lineOneSet(lineOne.begin(), lineOne.end());
        string lineTwo = "asdfghjkl";
        unordered_set lineTwoSet(lineTwo.begin(), lineTwo.end());
        string lineThree = "zxcvbnm";
        unordered_set lineThreeSet(lineThree.begin(), lineThree.end());
        vector<string> res;

        for (auto word : words)
        {
            auto set = lineThreeSet;
            auto flag = true;
            if (lineOneSet.count(tolower(word[0])) > 0)
            {
                set = lineOneSet;
            }
            else if (lineTwoSet.count(tolower(word[0])) > 0)
            {
                set = lineTwoSet;
            }
            for(auto ch :word){
                if(set.count(tolower(ch)) ==0) {
                    flag = false;
                    break;
                };
            }
            if(flag){
                res.push_back(word);
            }
        }
        return res;
    }
};
// @lc code=end
