// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem168.h"

using namespace std;
// @before-stub-for-debug-end

// 除26取余法
// 时间复杂度：O(log26 num) 
// 空间复杂度：O(1)

/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
class Solution
{
public:
    string convertToTitle(int num)
    {
        char startChar= 'A' -1;
        string st;

        while(num !=0){
            int cur = num%26 ;
            st.push_back((char)(startChar + (cur ==0 ? 26: cur)));
            num= (num-1) /26;
        }

        reverse(st.begin(),st.end());

        return st;
    }
};
// @lc code=end
