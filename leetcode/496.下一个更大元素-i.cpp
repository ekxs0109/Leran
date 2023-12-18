// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include "commoncppproblem496.h"

using namespace std;
// @before-stub-for-debug-end

// 时间复杂度：O(m+n)
// 空间复杂度：O(n)

/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int , int > hash;
        stack<int> stk;
        vector<int> res;


        for(auto it = nums2.rbegin(); it!=nums2.rend();it++){
            while(!stk.empty() && *it >=stk.top()){
                stk.pop();
            }

            hash[*it] = stk.empty()?-1 : stk.top();
            stk.push(*it);
        }

        for(auto num:nums1){
            res.push_back(hash[num]);
        }

        return res;



    }
};
// @lc code=end

