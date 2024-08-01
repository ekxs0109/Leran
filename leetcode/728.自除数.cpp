// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem728.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=728 lang=cpp
 *
 * [728] 自除数
 */

// @lc code=start
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        while(left <=right){
            bool flag = false;
            int val = left;

            while(val !=0){
                int cur = val%10;
                val /= 10;
                if(cur==0|| (left % cur) !=0){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                res.push_back(left);
            }
            left++;
        }

        return res;
    }
};
// @lc code=end

