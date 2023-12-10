// @before-stub-for-debug-begin
#include <algorithm>
#include <vector>
#include <string>
#include "commoncppproblem67.h"

using namespace std;
// @before-stub-for-debug-end

// 按位计算
// 时间复杂度：O(max(a,b))
// 空间复杂度：O(1)

/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1;
        int j = b.size()-1;

        bool flag = false;
        string res;

        while(i>=0 || j>=0 || flag){
            int cur = 0;
            if(flag){
                flag =false;
                cur++;
            }
            if(i>=0&&a[i--] =='1'){
                cur ++;
            }
            if(j>=0&&b[j--] =='1'){
                cur ++;
            }
            if(cur > 1){
                flag = true;
            }

            res.push_back((char)('0'+cur%2));
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end

