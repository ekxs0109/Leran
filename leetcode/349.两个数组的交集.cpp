// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_set>
#include "commoncppproblem349.h"

using namespace std;
// @before-stub-for-debug-end

// 用set空间换时间
// 时间复杂度：O(m+n) 存储set需要的时间
// 空间复杂度：O(m+n)

/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_set<int> set(nums1.begin(),nums1.end());
        unordered_set<int> set2(nums2.begin(),nums2.end()); 

        for(auto num : set2){
            if(set.count(num) >0){
                result.push_back(num);
            }
        }

        return result;
    }
};
// @lc code=end

