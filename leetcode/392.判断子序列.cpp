// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem392.h"

using namespace std;
// @before-stub-for-debug-end

//  双指针
// 换时间复杂度：O(p+q)
// 空间复杂度：O(1)

/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p = 0 ,q = 0 ;

        while (p< s.size()&& q< t.size() ){
            if(s[p] == t[q]){
                p++;
                q++;
            }else {
                q++;
            }
        }

        return p == s.size();
    }
};
// @lc code=end

