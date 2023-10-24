// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem905.h"

using namespace std;
// @before-stub-for-debug-end

// [3,1,2,4]
//  l     r  l%2!=0 l=r r--
// [4,1,2,3]
//  l     r  l%2==0 l++

// [3,1,2,4,5]
//  l       r r%2==0 r--

// 时间复杂度：O(n)
// 空间复杂度：O(1)

/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 */



// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l=0,r=nums.size()-1;

        while(l<=r){
            if(nums[r]%2 !=0 ){
                r--;
            }else if(nums[l]%2 ==0){
                l++;
            }else{
                swap(nums[l], nums[r]);
                r--;
            }
        }
        return nums;
    }
};
// @lc code=end

