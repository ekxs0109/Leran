// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem345.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
class Solution
{
public:
    string reverseVowels(string s)
    {
        int cnt[26] = {0};
        cnt[0]++;
        cnt['e' - 'a']++;
        cnt['i' - 'a']++;
        cnt['o' - 'a']++;
        cnt['u' - 'a']++;

        int startIndex = 0, endIndex = s.size() - 1;
        while (startIndex < endIndex)
        {
            auto asciiStart =  tolower(s[startIndex]) - 'a';
            auto asciiEnd = tolower(s[endIndex]) - 'a';
            if (asciiStart <0 || asciiStart>25  || !(cnt[asciiStart]))
            {
                startIndex++;
            }
            if ( asciiEnd <0 || asciiEnd>25 || !(cnt[asciiEnd]))
            {
                endIndex--;

            }

            if (!(asciiStart <0 || asciiStart>25  || !(cnt[asciiStart])) &&  !(asciiEnd <0 || asciiEnd>25 || !(cnt[asciiEnd])))
            {
                swap(s[startIndex], s[endIndex]);
                endIndex--;
                startIndex++;
            }
        }

        return s;
    }
};
// @lc code=end
