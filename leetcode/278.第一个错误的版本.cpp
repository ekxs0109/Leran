// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem278.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

//  n = 5 bad = 4
// p=0 q=5 m =2 false
// p=3 q=5 m=4  true;

//  n = 6 bad = 4
// p=0 q=6 m=3 false
// p=4 q=6 m=5  true;
// p=4 q=4 m=4 true

// 使用二分法
// 时间复杂度：O(log n)
// 空间复杂度：O(1)

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int p=0, q=n,mid =0,result = 0;

        while (p<=q){
            mid = ((q-p)>>1) + p;

            if(isBadVersion(mid)){
                result = mid;
                q = mid-1;
            }else{
                p = mid +1;
            }

        }
        return result;
        
    }
};
// @lc code=end

