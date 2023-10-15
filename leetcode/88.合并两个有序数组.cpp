// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem88.h"

using namespace std;
// @before-stub-for-debug-end

// [5,6,7,0,0,0] [2,5,6] 3 3
//      m     p       n
// [5,6,7,0,0,7] [2,5,6] 3 3
//    m     p       n
// [5,6,7,0,6,7] [2,5,6] 3 3
//  m     p         n
// [5,6,7,5,6,7] [2,5,6] 3 3
//m^    p           n


// 倒叙指针，将第二个数组完全插入到第一个数组结束
// 时间复杂度：O(n)
// 空间复杂度：O(1)

/*

 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int p = nums1.size()-1;
        m--;n--;
        while(n>-1){  // 判断第二个数组都插入到了第一个数组就结束
            if(m>-1 && nums1[m] >= nums2[n]){
                nums1[p--] = nums1[m--];
            }else{
                nums1[p--] = nums2[n--];
            }
        }
    }
};
// @lc code=end
