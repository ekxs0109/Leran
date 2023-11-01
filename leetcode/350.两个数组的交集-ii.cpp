// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem350.h"

using namespace std;
// @before-stub-for-debug-end

// 1,1,2,2
// p       p < q  p++
// 2,2
// q

// 排序 + 双指针
// 时间复杂度：O(m log m + n log n) m 和 n分别为nums1和2的长度
// 空间复杂度：O(1) 只存储了返回值，不算空间复杂度

/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        sort(nums1.begin(),nums1.end());

        sort(nums2.begin(), nums2.end());
        int p=0,q=0;

        while (p<nums1.size() && q< nums2.size()){
            if(nums1[p] == nums2[q]){
                result.push_back(nums1[p]);
                p++;
                q++;
            }else if ( nums1[p] > nums2[q] ){
                q++;
            }else{
                p++;
            }
        }
        return result;
    }
};
// @lc code=end

