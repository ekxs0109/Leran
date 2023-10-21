// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem495.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */

//  [1,4] 2
//  12 45
//  4-1+2-1 cur = 3

// [1,2] 2
// 2-1+2-1  cur = 2
// @lc code=start
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0,last =0;

        for(auto time : timeSeries){
            if(last ==0 ) {
                last = time;
            }else{
                if(time< (last+duration-1)){
                    // res+=(last+duration) -time;
                }else{
                    res+=duration;
                    last = time;
                }
            }
        }
        if(last !=0){
            res+=duration;
        }
        return res;
    }
};
// @lc code=end

