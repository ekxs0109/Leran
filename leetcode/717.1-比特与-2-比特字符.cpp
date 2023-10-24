// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem717.h"

using namespace std;
// @before-stub-for-debug-end

// [1,0,0,0,1,1,0]

// 使用递归的方式解决
// 时间复杂度：O(n)
// 空间复杂度：O(1)

/*
 * @lc app=leetcode.cn id=717 lang=cpp
 *
 * [717] 1 比特与 2 比特字符
 */

// @lc code=start
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int len = bits.size();
        auto func = [&bits,&len](auto&& self,int begin)->bool {
            if(begin+1>len) return false;
            if(bits[begin] == 0){
                if(begin==len -1){
                    return true;
                }
                return self(self,begin+1);
            }
            if(begin+1<len && bits[begin]==1 && (bits[begin+1]==1  || bits[begin+1]==0)){
                return self(self,begin+2);
            }
            return false;
        };
        return func(func,0);
    }
};
// @lc code=end

