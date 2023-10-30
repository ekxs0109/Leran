// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem401.h"

using namespace std;
// @before-stub-for-debug-end

// 3
// 直接遍历解， __builtin_popcount获取二进制 1的总数
// 时间复杂度：O(1) . 遍历与外部参数无关
// 空间复杂度：O(1)

/*
 * @lc app=leetcode.cn id=401 lang=cpp
 *
 * [401] 二进制手表
 */

// @lc code=start
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for(int i = 0 ;i<12 ; i++ ){
            for(int j =0; j < 60; j++){

                if((__builtin_popcount(i) + __builtin_popcount(j)) == turnedOn){
                    res.push_back(to_string(i) + ":" + (j<10?"0":"")+ to_string(j));
                }
            }
        }
        return res;
    }
};
// @lc code=end

