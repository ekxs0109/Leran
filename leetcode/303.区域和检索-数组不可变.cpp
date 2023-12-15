// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem303.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
private:
    vector<int> res;
public:
    NumArray(vector<int>& nums) {
        res = nums;
    }
    
    int sumRange(int left, int right) {
        int r = 0;
        for(auto it = res.begin()+left ;  it != res.begin()+right+1 ;it++ ){
            r+=*it;
        }
        return r;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

