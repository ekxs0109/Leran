// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem263.h"
#include <algorithm>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
class Solution {
public:
    bool isUgly(int n) {

        if(n <=0) return false;

        vector<int>  factors = {2,3,5};

        for(auto i: factors){
            while(n%i == 0){
                n /= i;
            }
        }
        return n==1;
    
    }
};
// @lc code=end

