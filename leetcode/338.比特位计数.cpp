// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem338.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution {
public:
    inline int hammingWeight(uint32_t n) {
        int res = 0;
        for(int i =0 ;i < 32;i++){
            if(n&1 == 1){
                res ++;
            }
            n>>=1;
        }
        return res;
    }
    vector<int> countBits(int n) {
        vector<int>  res;
        for(int i = 0 ; i<= n;i++){
            res.push_back(this->hammingWeight(i));
        }
        return res;
    }
};
// @lc code=end

