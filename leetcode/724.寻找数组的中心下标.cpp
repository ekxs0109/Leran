// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem724.h"

using namespace std;
// @before-stub-for-debug-end


// [1, 7, 3, 6, 5, 6]
//  p                需要从最左开始
//        p          l=8 r=17 l<r  不包含p所在值
//           p       l=8+3 r=17-6 l==6  true

// [1, 2, 3]
//     p       l=1 r=3 l<p
//        p    l=1+2 r=3-3   &&  p==len-1  false


// 时间复杂度为 O(n)
// 空间复杂度为 O(1)


/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */


// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int p = 0,len = nums.size(),lSum=0,rSum=0;

        for(int i=1;i<len;i++){
            rSum += nums[i];
        }

        if(lSum == rSum) return p;
        while(p<len-1){
            p++;
            lSum+=nums[p-1];
            rSum-=nums[p];
            if(lSum == rSum) return p;
        }
        return -1;
    }
};
// @lc code=end

