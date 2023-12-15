// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem344.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int mid = s.size() >>1, len =s.size()-1;
        for(int i = 0 ; i<mid ;i++){
            swap(s[i], s[len-i]);
        }
    }
};
// @lc code=end

