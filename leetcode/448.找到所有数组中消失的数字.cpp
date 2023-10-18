// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
#include "commoncppproblem448.h"

using namespace std;
// @before-stub-for-debug-end

// [1,2,2,4,5]
//  i        q=1 iq++
// [1,2,2,4,5]
//    i      q=2 i==i+1 i++
// [1,2,2,4,5]
//      i    q=2 iq++
// [1,2,2,4,5]
//        i  q=3 res=[3] q++

// 通过排序+指针遍历
// 时间复杂度：O(n)
// 空间复杂度：O(1)

// 268的修改版本
// 时间复杂度：O(n)
// 空间复杂度：O(n)

/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> res;
        int q = 1;
        int i = 0;
        while(q<=len&&i<=len){
             if(i+2<len && nums[i] == nums[i+1]){
                i++;
            } else if(q!= nums[i]){
                res.push_back(q++);
            }else{
                i++;
                q++;
            }
        }
        return res;
    }
    vector<int> findDisappearedNumbersBySet(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> res;
        unordered_set<int> set(nums.begin(), nums.end());
        for (int i = 1; i <= len; i++)
        {
            if (!set.count(i))
            {
                res.push_back(i);
            };
        }
        return res;
    }
};
// @lc code=end
