// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem66.h"

using namespace std;
// @before-stub-for-debug-end

// [1,2,3]
// [1,2,4]

// [9,9,9]
// [1,0,0,0]

// 用后向前遍历,如果非9，就直接+1 return
// 时间复杂度：O(n)
// 空间复杂度：O(1)
/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int p = digits.size()-1;

        while(p>-1){
            if(digits[p] ==9 ){
                digits[p]=0;
                p--;
            }else{
                digits[p] = digits[p]+1;
                return digits;
            }
        }

        digits.insert(digits.begin(),1);
        return digits;
    }
};
// @lc code=end

