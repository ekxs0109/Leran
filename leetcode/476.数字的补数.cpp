// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <iostream>
#include "commoncppproblem476.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 */

// @lc code=start
class Solution {
public:
    int findComplement(int n) {
        int highbit = 0;
        for(int i =1 ;i <=30 ; ++i){
            if(n >= (1<<i)){
                highbit = i;
            }else{
                break;
            }
        }

        int mask = (highbit==30 ? 0x7fffffff: (1<< (highbit+1)) -1);
        return n^mask;
    }
};
// @lc code=end

